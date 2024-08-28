LIBRARY IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity SR_LATCH is

port
(
S,R 	: 	IN 	STD_LOGIC;
Q		:	INOUT	STD_LOGIC


);
end SR_LATCH;

architecture Behavioral of SR_LATCH is
signal notQ: std_logic;

begin
	Q <= R nor notQ;
	notQ <= Q nor S;
	
end behavioral;
