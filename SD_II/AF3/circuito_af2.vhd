------------------------------------------------------------------------
-- Arquivo   : circuito_af2.vhd
-- Projeto   : Atividade Formativa 2 - PCS3225
------------------------------------------------------------------------
-- Descricao : Circuito Principal
------------------------------------------------------------------------
-- Revisoes  :
-- Data        Versao  Autor                  Descricao
-- 15/08/2025  1.0     Antonio V. da S. Neto  Versao inicial.
-------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

-- Descricao da Entidade
entity circuito_af2 is
  port (
        clock         : in  std_logic;
		inicio        : in  std_logic;
        reset         : in  std_logic;
        contagem      : out std_logic_vector (3 downto 0);
		memoria       : out std_logic_vector (3 downto 0);
		db_estado     : out std_logic_vector (3 downto 0)
		  
  );
end entity;

-- Descricao da Arquitetura Estrutural
architecture estrutural of circuito_af2 is

  component fluxo_dados
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
  end component;

  component unidade_controle
    port ( 
        clock        :   in  std_logic;
        inicio       :   in  std_logic;
        reset        :   in  std_logic;
        fim_contagem :   in  std_logic;
        enable       :   out std_logic;
        reset_auto   :   out std_logic;
        sel_escreve  :   out std_logic;
        controle_ram :   out std_logic;
        db_estado    :   out std_logic_vector(3 downto 0)
    );
  end component;
  
  signal s_sel_escreve, s_fim_contagem, s_reset_auto, s_controle_ram, s_enable : std_logic;
  
begin
  
  FD: fluxo_dados
    port map (
        clock        => clock,
        reset        => reset,
        sel_escreve  => s_sel_escreve,
        controle_ram => s_controle_ram,
		reset_auto   => s_reset_auto,
		enable       => s_enable,
		fim_contagem => s_fim_contagem,
        contagem     => contagem, 
        memoria      => memoria
    );
	 
	UC: unidade_controle
	  port map (
	    clock        => clock,
		inicio       => inicio,
		reset        => reset,
		fim_contagem => s_fim_contagem,
		enable       => s_enable,
		reset_auto   => s_reset_auto,
		sel_escreve  => s_sel_escreve,
		controle_ram => s_controle_ram,
		db_estado    => db_estado
	  );			

end estrutural;
