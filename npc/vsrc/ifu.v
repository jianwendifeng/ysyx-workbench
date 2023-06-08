module pc #(RESET_VAL = 32'h80000000) (
  input clk,
  input rst,
  output reg [31:0] pc_out
);

	always @ (posedge clk) begin
		if(rst) pc_out <= RESET_VAL;
		else pc_out <= pc_out + 4 ;
	end

endmodule

module inst_rom(
	input [32-1:0] inst_addr,
	output [32-1:0] inst_data
);

	reg [31:0] memory [31:0];
	initial begin
		//initial inst_reg
		memory[0] =	32'b00000000010101000001010100110011;	//#addi x6, x5, 20
		memory[1]	= 32'b11111111111111111111111111100111;	//#addi x8, x7, -7
		memory[2]	= 32'b00000000011001000001001000110011;	//#addi x10, x9, 100
		memory[3] = 32'b00000000000100000000000001110011;	//#ebreak
	end

	assign inst_data = memory[inst_addr - 32'h80000000];

endmodule

module ifu (
	input clk,
	input rst,
	output reg [31:0] ifu_out
);

wire [31:0] pc_rom;

pc pc0(
	.clk(clk),
	.rst(rst),
	.pc_out(pc_rom)
);

inst_rom inst_rom0(
	.inst_addr(pc_rom),
	.inst_data(ifu_out)
);

endmodule
