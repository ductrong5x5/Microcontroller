library IEEE;
use ieee.std_logic_1164.all;

entity mux21_8 is
port(

d0 : In STD_LOGIC_VECTOR ( 7 DOWNTO 0);
d1 : IN STD_LOGIC_VECTOR ( 7 DOWNTO 0);
SEL : IN STD_LOGIC;
DATA_OUT :OUT STD_LOGIC_VECTOR (7 DOWNTO 0)


);

architecture Behavioral of mux21_8 is
begin
DATA_OUT <= d0 when (SEL ='0') else
				d1 when (SEL ='1');
				


end Behavioral;