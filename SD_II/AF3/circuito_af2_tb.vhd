------------------------------------------------------------------------
-- Arquivo   : circuito_af2_tb.vhd
-- Projeto   : Atividade Formativa 2 - PCS3225
------------------------------------------------------------------------
-- Descricao : Testbench da Entidade circuito_af2
------------------------------------------------------------------------
-- Revisoes  :
-- Data        Versao  Autor                  Descricao
-- 15/08/2025  1.0     Antonio V. da S. Neto  Versao inicial.
-------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use std.textio.all;

-- entidade do testbench
entity circuito_af2_tb is
end entity;

architecture tb of circuito_af2_tb is

  -- Componente a ser testado (Device Under Test -- DUT)
  component circuito_af2
    port (
        clock         : in  std_logic;
		inicio        : in  std_logic;
        reset         : in  std_logic;
        contagem      : out std_logic_vector (3 downto 0);
		memoria       : out std_logic_vector (3 downto 0);
		db_estado     : out std_logic_vector (3 downto 0)
    );
  end component;
  
  ---- Declaracao de sinais de entrada para conectar o componente
  signal clk_in:     std_logic := '0';
  signal inicio_in:  std_logic := '0';
  signal rst_in:     std_logic := '0';

  ---- Declaracao dos sinais de saida
  signal contagem_hexaout:   std_logic_vector(3 downto 0) := "0000";
  signal memoria_hexaout:    std_logic_vector(3 downto 0) := "0000";
  signal db_estado_out:      std_logic_vector(3 downto 0) := "0000";

  -- Configurações do clock
  signal keep_simulating: std_logic := '0'; -- delimita o tempo de geração do clock
  constant clockPeriod : time := 10 ms;     -- frequencia 100Hz
  
begin
  -- Gerador de clocks: executa enquanto 'keep_simulating = 1', com o período especificado. 
  -- Quando keep_simulating=0, clock é interrompido, bem como a simulação de eventos
  clk_in <= (not clk_in) and keep_simulating after clockPeriod/2;
  
  ---- DUT para Caso de Teste
  dut: circuito_af2
       port map
       (
          clock         => clk_in,
          inicio        => inicio_in,
          reset         => rst_in,
          contagem      => contagem_hexaout,
          memoria	    => memoria_hexaout,
          db_estado     => db_estado_out
       );
 
  -- Gera sinais de estimulo para a simulacao
  stimulus: process is
  begin

    -- inicio da simulacao
    assert false report "inicio da simulacao" severity note;
    keep_simulating <= '1';

    -- gera pulso de reset (1 periodo de clock)
    rst_in <= '1';
    wait for clockPeriod;
    rst_in <= '0';

    wait until falling_edge(clk_in);
    -- pulso do sinal de Iniciar
    inicio_in <= '1';
    wait until falling_edge(clk_in);
    inicio_in <= '0';

    -- espera execução de ciclo completo
    wait for 80*clockPeriod;

    ---- final do testbench
    assert false report "fim da simulacao" severity note;
    keep_simulating <= '0';
    
    wait; -- fim da simulação: processo aguarda indefinidamente
  end process;

end architecture;

