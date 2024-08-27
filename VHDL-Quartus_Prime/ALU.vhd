LIBRARY IEEE;
use IEEE.STD_LOGIC_1164.ALL;

use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.all;

entity ALU is

port
(
A,B 	: in STD_LOGIC_VECTOR(7 DOWNTO 0);
OP		: IN STD_LOGIC_VECTOR(2 DOWNTO 0);
Result: out STD_LOGIC_VECTOR(7 DOWNTO 0);
Carryout	: out STD_LOGIC
);

end ALU;
architecture Behavioral of ALU is
signal ALU_RESULT: std_logic_vector (7 DOWNto 0);
signal temp : std_logic_vector (8 DOWNTO 0);



begin
	process (A,B,OP)
	begin
		case (OP) is
			when "000" => --add
			ALU_RESULT <= A+B;
			when "001" => --subtract
			ALU_RESULT <= A-B;
			when "010" => --Mul
			ALU_RESULT <= std_logic_vector(to_unsigned(to_integer(unsigned(A))* to_integer(unsigned(B)),8));
			when "011" => --Div
			ALU_RESULT <= std_logic_vector(to_unsigned(to_integer(unsigned(A))/ to_integer(unsigned(B)),8));
			when "100" => --XOR
			ALU_RESULT <= A XOR B;
			when "101" => --XNOR
			ALU_RESULT <= A XNOR B;
			when "110" => --Equal
				if( A=B) then
					ALU_RESULT <= x"01";
				else
					ALU_RESULT <= x"00";
				end if;
			when "111" => --Bigger
			if( A>B) then
					ALU_RESULT <= x"01";
				else
					ALU_RESULT <= x"00";
				end if;
		end case;
	end process;
	Result <= ALU_RESULT;
	temp <= ('0' & A) + ('0' & B);
	Carryout <= temp(8);
end Behavioral;
