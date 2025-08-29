------------------------------------------------------------------------
-- Arquivo   : fluxo_dados.vhd
-- Projeto   : Atividade Formativa 2 - PCS3225
------------------------------------------------------------------------
-- Descricao : Fluxo de Dados do Circuito
------------------------------------------------------------------------
-- Revisoes  :
-- Data        Versao  Autor                  Descricao
-- 15/08/2025  1.0     Antonio V. da S. Neto  Versao inicial.
-------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

-- Descricao da Entidade
entity fluxo_dados is
   port (
        clock         : in  std_logic;
        reset         : in  std_logic;
        sel_escreve   : in  std_logic;
        controle_ram  : in  std_logic;
	    reset_auto    : in  std_logic;
	    enable        : in  std_logic;
        fim_contagem  : out std_logic;		  
        contagem      : out std_logic_vector (3 downto 0);
	    memoria       : out std_logic_vector (3 downto 0)
   );
end entity fluxo_dados;

-- Descricao da Arquitetura Estrutural
architecture estrutural of fluxo_dados is
  signal s_not_reset        : std_logic;
  signal s_not_controle_ram : std_logic;
  signal s_contagem         : std_logic_vector (3 downto 0);
  signal s_dado_escreve     : std_logic_vector (3 downto 0);
  signal s_contagem_00_32   : std_logic_vector (3 downto 0);
  
  component contador_163
    port (
        clock : in  std_logic;
        clr   : in  std_logic;
        ld    : in  std_logic;
        ent   : in  std_logic;
        enp   : in  std_logic;
        D     : in  std_logic_vector (3 downto 0);
        Q     : out std_logic_vector (3 downto 0);
        rco   : out std_logic 
    );
  end component;

  component ram_16x4
    port (
       clk          : in  std_logic;
       endereco     : in  std_logic_vector(3 downto 0);
       dado_entrada : in  std_logic_vector(3 downto 0);
       n_we         : in  std_logic;
       n_cs         : in  std_logic;
       dado_saida   : out std_logic_vector(3 downto 0)
    );
  end component;
  
  component mux2x1_n is
    generic (
        constant BITS: integer := 4
    );
    port(
        D0      : in  std_logic_vector (BITS-1 downto 0);
        D1      : in  std_logic_vector (BITS-1 downto 0);
        SEL     : in  std_logic;
        MUX_OUT : out std_logic_vector (BITS-1 downto 0)
    );
  end component;


begin

  s_not_reset <= not (reset or reset_auto);
  s_not_controle_ram <= not controle_ram;
  contagem <= s_contagem;
  s_contagem_00_32 <= "00" & s_contagem(3 downto 2);
  
  contador: contador_163
    port map (
        clock => clock,
        clr   => s_not_reset,
        ld    => '1',
        ent   => '1',
        enp   => enable,
        D     => "0000",
        Q     => s_contagem,
        rco   => fim_contagem
    );

  ram: entity work.ram_16x4(ram_modelsim)
    port map (
       clk          => clock,
       endereco     => s_contagem,
       dado_entrada => s_dado_escreve,
       n_we         => s_not_controle_ram,
       n_cs         => '0',
       dado_saida   => memoria
    );
	 
   mux: mux2x1_n
     generic map (
       BITS => 4
     )
    port map (
       D0          => s_contagem,
       D1          => s_contagem_00_32,
       SEL         => sel_escreve,
       MUX_OUT     => s_dado_escreve
    );
  
end estrutural;
