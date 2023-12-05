module ram1(addr, data_in, data_out, wr_en, clk);

/**********************************************************/
/********* Modify these parameters as you see fit *********/
/**********************************************************/
parameter N = 64; // size of each word
parameter ADDR_BITS = 4; // number of words = 2^ADDR_BITS 
/**********************************************************/


parameter NUM_WORDS = 1 << ADDR_BITS;
parameter RAM_DEPTH = NUM_WORDS*N;

input [ADDR_BITS-1:0] addr;
input [N-1:0] data_in;
output [N-1:0] data_out;
input wr_en, clk;

reg [N-1:0] ram [0:NUM_WORDS-1];
reg [N-1:0] internal_bus;

always @(posedge clk) begin
    if (wr_en == 1) begin
        ram[addr] = data_in;    // load value into memory
        internal_bus = ram[addr];   // update what's at the output
    end
end

assign data_out = internal_bus;

/** WIRE Implementation - Size dependent, need to rewrite for different sizes **/
//wire [RAM_DEPTH-1:0] ram_wire;
//assign ram_wire = {ram[15],ram[14],ram[13],ram[12],ram[11],ram[10],ram[9],ram[8],ram[7],ram[6],ram[5],ram[4],ram[3],ram[2],ram[1],ram[0]};


/** REG Implementation - Size independent, no rewriting required, just note how each word is indexed in RAO file  **/
reg [RAM_DEPTH-1:0] ram_reg;
reg [NUM_WORDS-1:0] row;
reg [N-1:0] bit;

always @(posedge clk) begin
    for(row=0; row<NUM_WORDS; row=row+1) begin
        for(bit=0; bit<N; bit=bit+1) begin
            ram_reg[row*N+bit] = ram[row][bit];
        end
    end
end

endmodule
