LIBRARY IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity DFF_8 is
port
(
D: IN STD_LOGIC_VECTOR(7 downto 0);
CLK , RST : in STD_LOGIC;
Q		: out STD_logic_VECTOR(7 downto 0)

);
end DFF_8;

architecture Behavioral of DFF_8 is
begin
	process(CLK,RST)
	begin
		if RST ='1' then
			Q<= (others => '0');
		elsif (rising_edge(CLK)) then
			Q<=D;
		end if;
	end process;
end Behavioral;