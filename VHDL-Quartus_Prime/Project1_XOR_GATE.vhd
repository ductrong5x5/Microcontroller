library IEEE; 
use IEEE.STD_LOGIC_1164.ALL;


entity Project1_XOR_GATE is
port --- put input and out put here
(
INPUT_A, INPUT_B, INPUT_C : IN STD_LOGIC;
OUTPUT : OUT STD_LOGIC
);

end Project1_XOR_GATE;
Architecture behavioral of Project1_XOR_GATE is
begin

OUTPUT<= INPUT_A XOR INPUT_B XOR INPUT_C;


end behavioral;