LIBRARY IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity FSM is
port
(
clock: in std_logic;
reset: in std_logic;
acc,start: in std_logic;
STATE_OUT: out std_logic_vector( 2 downto 0);
WRA,WRB,WRC,SEL : out std_logic
);
end FSM;

architecture Behavioral of FSM is
type state is (init, fetch, procc, write_result,accc);
signal current_state, next_state: state;
begin
	process(clock, reset)
		begin
			if (reset ='1') then
				current_state <=init;
			elsif(falling_edge(clock)) then
				current_state <=next_state;
			end if;
		end process;
	
	process(start,acc)
	begin
		case(current_state) is
			when init => 
				STATE_OUT<="000";
				WRA <= '0';
				WRB <= '0';
				WRC <= '0';
				SEL <= '0';
				IF( START ='1' and acc='0') then 
					next_state <=fetch;
				elsif ( START ='1' and acc='1') then
					next_state <=accc;
				else
					next_state <= init;
				end if;
			when fetch =>
				STATE_OUT<="001";
				WRA <= '1';
				WRB <= '1';
				WRC <= '0';
				SEL <= '0';
				next_state<=procc;
			when accc =>
				STATE_OUT<="010";
				WRA <= '0';
				WRB <= '0';
				WRC <= '1';
				SEL <= '1';
				next_state<=procc;
			when procc =>
				STATE_OUT<="011";
				WRA <= '0';
				WRB <= '0';
				next_state<=write_result;
			when write_result =>
				STATE_OUT<="100";
				WRA <= '0';
				WRB <= '0';
				WRC <= '1';
				SEL <= '0';
				next_state<=init;
		end case;
	end process;
end behavioral;
		