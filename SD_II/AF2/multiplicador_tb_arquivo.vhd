-------------------------------------------------------
--! @file multiplicador_tb_arquivo.vhd
--! @brief testbench for synchronous multiplier
--! @author Edson Midorikawa (emidorik@usp.br)
--! @date 2020-06-15
-------------------------------------------------------

library ieee;
use ieee.numeric_bit.all;
use std.textio.all;

entity multiplicador_tb_arquivo is
end entity;

architecture tb of multiplicador_tb_arquivo is
  
  -- Componente a ser testado (Device Under Test -- DUT)
  component multiplicador
    port (
      Clock:    in  bit;
      Reset:    in  bit;
      Start:    in  bit;
      Va,Vb:    in  bit_vector(3 downto 0);
      Vresult:  out bit_vector(7 downto 0);
      Ready:    out bit
    );
  end component;
  
  -- Declaração de sinais para conectar a componente
  signal clk_in: bit := '0';
  signal rst_in, start_in, ready_out: bit := '0';
  signal va_in, vb_in: bit_vector(3 downto 0);
  signal result_out: bit_vector(7 downto 0);

  -- Configurações do clock
  signal keep_simulating: bit := '0'; -- delimita o tempo de geração do clock
  constant clockPeriod : time := 1 ns;
  
begin
  -- Gerador de clock: executa enquanto 'keep_simulating = 1', com o período
  -- especificado. Quando keep_simulating=0, clock é interrompido, bem como a 
  -- simulação de eventos
  clk_in <= (not clk_in) and keep_simulating after clockPeriod/2;
  
  ---- O código abaixo, sem o "keep_simulating", faria com que o clock executasse
  ---- indefinidamente, de modo que a simulação teria que ser interrompida manualmente
  -- clk_in <= (not clk_in) after clockPeriod/2; 
  
  -- Conecta DUT (Device Under Test)
  dut: multiplicador
       port map(Clock=>   clk_in,
                Reset=>   rst_in,
                Start=>   start_in,
                Va=>      va_in,
                Vb=>      vb_in,
                Vresult=> result_out,
                Ready=>   ready_out
      );

  ---- Gera sinais de estimulo
  stimulus: process is

    file tb_file : text open read_mode is "multiplicador_tb_estimulos.txt";
    variable tb_line: line;
    variable space: character;
    variable Vb_in_file, Va_in_file: bit_vector(3 downto 0);
    variable result_out_file: bit_vector(7 downto 0);
  begin

    assert false report "Simulation start." severity note;
    keep_simulating <= '1';

    rst_in <= '1'; start_in <= '0';
    wait for clockPeriod;
    rst_in <= '0';
    wait until falling_edge(clk_in);
    
    while not endfile(tb_file) loop
      readline(tb_file, tb_line);
      read(tb_line, Va_in_file);
      read(tb_line, space);
      read(tb_line, Vb_in_file);
      read(tb_line, space);
      read(tb_line, result_out_file);


      Va_in <= Va_in_file;
      Vb_in <= Vb_in_file;
      
      wait until falling_edge(clk_in);
      start_in <= '1';
      wait until falling_edge(clk_in);
      start_in <= '0';
      wait until ready_out = '1';

      assert result_out = result_out_file report "Erro na multiplicacao: " & 
        integer'image(to_integer(unsigned(Va_in_file))) & " * " &
        integer'image(to_integer(unsigned(Vb_in_file))) severity error;

      wait for clockPeriod;
    end loop;

    assert false report "simulation end" severity note;
    keep_simulating <= '0';
    
    wait; -- fim da simulação: aguarda indefinidamente
  end process;


end architecture;
