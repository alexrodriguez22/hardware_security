module top(CLK_50, CLK_OSC_2, CM, CLK_inter, SPI_SS, SPI_MISO, SPI_SCLK, SPI_MOSI, FLASH_WP_n, FLASH_HOLD_n, LED, SEG, KEY, SW);
	/* FPGA Clocks */
	input CLK_50;
	input CLK_OSC_2;
	
	/* Chip Interconnect */
	input [7:0] CM;		// connects to PA0-7 (all of PORTA) of Xmega
                        // CM0 requires SSPI to be set as regular IO
	input CLK_inter; 	// connects to PC0 of Xmega
	
	/* SPI & Flash - FPGA as master configuration - change as needed */
	output SPI_SS;			// SS port - connects to PC4
	input SPI_MISO;			// MISO port - connects to PC6
	output SPI_SCLK;		// SCLK port - connects to PC7
	output SPI_MOSI;		// SCLK port - connects to PC5
	output FLASH_WP_n;		// WP_n port - connects to PE2
	output FLASH_HOLD_n;	// HOLD_n port - connects to PE1
	
	/* FPGA User Interface */
	output [7:0] LED;	// yellow LEDs
	output [7:0] SEG;	// 7 segment display: light up = '0', no light = '1'
						// SEG[6:0] lights up G,F,...,A sections, respectively
						// SEG[7] lights up display point (DP)
	
	/* FPGA Button/Switch */
	input [2:0] KEY;	// key buttons
	input [9:0] SW;		// switches: switch up = '0', switch down = '1'
	
	
	/* FPGA GPIO - Add GPIOs based on HaHa manual*/
	//des des(
        //.clk_in(clk_in),
        //.rst(rst)
    //);
    des des_instance (CLK_50, -SW[9]);
	
	/* Add the remaining circuitry from here*/

endmodule
