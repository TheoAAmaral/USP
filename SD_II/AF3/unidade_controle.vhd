------------------------------------------------------------------------
-- Arquivo   : unidade_controle.vhd
-- Projeto   : Atividade Formativa 2 - PCS3225
------------------------------------------------------------------------
-- Descricao : Unidade de Controle do Circuito
------------------------------------------------------------------------
-- Revisoes  :
-- Data        Versao  Autor                  Descricao
-- 15/08/2025  1.0     Antonio V. da S. Neto  Versao inicial.
-------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

-- Descricao da Entidade
entity unidade_controle is 
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
end entity;

-- Descricao da Maquina de Estados da UC
architecture mef_moore of unidade_controle is

  type t_estado is (inicial, le1, escreve, le2, escreve2, le3);
  signal Eatual, Eprox: t_estado;
  
begin
  process (clock, reset)
  begin
  
    if (reset = '1') then
	    Eatual <= inicial;
		 
    elsif (clock'event and clock = '1') then
	    Eatual <= Eprox;
		 
    end if;
	 
  end process;

  --logica de proximo estado
  Eprox <=    inicial  when  Eatual=inicial  and inicio = '0'    else
              le1      when  Eatual=inicial  and inicio = '1'    else
				  escreve  when  Eatual=le1      and fim_contagem = '1' else
				  le1      when  Eatual=le1      and fim_contagem = '0' else
				  le2      when  Eatual=escreve  and fim_contagem = '1'  else
				  escreve  when  Eatual=escreve  and fim_contagem = '0' else
				  escreve2 when  Eatual=le2      and fim_contagem = '1'  else
				  le2      when  Eatual=le2      and fim_contagem = '0' else
				  le3      when  Eatual=escreve2 and fim_contagem = '1'  else
				  escreve2 when  Eatual=escreve2 and fim_contagem = '0' else
				  inicial  when  Eatual=le3      and fim_contagem = '1'  else
				  le3      when  Eatual=le3      and fim_contagem = '0' else
				  inicial;

  --logica de saída (maquina de Moore)
  with Eatual select
       reset_auto <=   '1' when inicial,
                       '0' when others;
							  
  with Eatual select
       enable <=       '0' when inicial,
                       '1' when others;

  with Eatual select
       controle_ram <= '1' when escreve | escreve2,
                       '0' when others;
							  
  with Eatual select
       sel_escreve <=  '1' when escreve2,
		                 '0' when others;

  -- saida de depuracao (db_estado)
  with Eatual select
       db_estado <= "0001" when inicial,
                    "0010" when le1,
                    "0100" when escreve,
                    "1000" when le2,
						  "0101" when escreve2,
						  "1001" when le3,
                    "1111" when others; -- F
end mef_moore;