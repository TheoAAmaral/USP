-------------------------------------------------------------------
-- Arquivo : ram_16x4.vhd
-- Projeto : Nao aplicavel.
-------------------------------------------------------------------
-- Descricao : modulo de memoria RAM sincrona 16x4
-- sinais /we e /cs ativos em baixo
-- codigo ADAPTADO do codigo encontrado no livro
-- VHDL Descricao e Sintese de Circuitos Digitais
-- de Roberto D'Amore, LTC Editora.
-------------------------------------------------------------------
-- Revisoes:
-- Data       Versao Autor               Descricao
-- 08/01/2020 1.0    Edson Midorikawa    Criacao
-- 01/02/2021 2.0    Antonio V.S.Neto    Atualizacao para
--                                       RAM sincrona para
--                                       minimizar problemas
--                                       com Quartus.
-- 02/02/2021 2.1    Edson Midorikawa    Revisao de codigo e
--                                       arquitetura para
--                                       simulacao com ModelSim
-- 01/02/2021 2.2    Antonio V.S.Neto    Atualizacao para P1 de
--                                       PCS3635
-- 15/08/2025 3.0    Antonio V.S.Neto    Revisao para PCS3225.
-------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ram_16x4 is
    port (
        clk          : in  std_logic;
        endereco     : in  std_logic_vector(3 downto 0);
        dado_entrada : in  std_logic_vector(3 downto 0);
        n_we         : in  std_logic;
        n_cs         : in  std_logic;
        dado_saida   : out std_logic_vector(3 downto 0)
    );
end entity ram_16x4;

architecture ram_mif of ram_16x4 is
    type    arranjo_memoria is array(0 to 15) of std_logic_vector(3 downto 0);
    signal memoria : arranjo_memoria;

    -- Configuracao do Arquivo MIF
    attribute ram_init_file: string;
    attribute ram_init_file of memoria: signal is "ram_v0.mif";

begin

    process (clk)
    begin
        if (clk'event and clk = '1') then
            if n_cs = '0' then -- dado armazenado com "we=0" e "ce=0"

                -- Detecta ativacao de we (ativo baixo)
                if (n_we = '0') then -- Escrita
                    memoria(to_integer(unsigned(endereco))) <= dado_entrada;
                else -- Leitura
                    dado_saida <= memoria(to_integer(unsigned(endereco)));
                end if;

            else -- Saídas em alta impedancia de a pastilha está desligada.

                dado_saida <= (others => 'Z');

            end if;
        end if;
    end process;

end architecture ram_mif;

-- Dados iniciais (para simulacao com Modelsim)
architecture ram_modelsim of ram_16x4 is
    type    arranjo_memoria is array(0 to 15) of std_logic_vector(3 downto 0);
    signal memoria : arranjo_memoria := (
        "1111",
        "0000",
        "1110",
        "0001",
        "1101",
        "0010",
        "1100",
        "0011",
        "1011",
        "0100",
        "1010",
        "0101",
        "1001",
        "0110",
        "1000",
        "0111"
    );

begin

    process (clk)
    begin
        if (clk'event and clk = '1') then
            if n_cs = '0' then -- dado armazenado com "we=0" e "ce=0"

                -- Detecta ativacao de we (ativo baixo)
                if (n_we = '0') then -- Escrita
                    memoria(to_integer(unsigned(endereco))) <= dado_entrada;
                else -- Leitura
                    dado_saida <= memoria(to_integer(unsigned(endereco)));
                end if;

            else -- Saídas em alta impedancia de a pastilha está desligada.

                dado_saida <= (others => 'Z');

            end if;
        end if;
    end process;

end architecture ram_modelsim;