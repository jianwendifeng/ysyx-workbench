module inst_rom(
	input [32-1:0] inst_addr,
	output [32-1:0] inst_data
);

	reg [31:0] memory [63:0];
	initial begin
		//initial inst_reg
		memory[0] =	00000000010101000001010100110011;	//#addi x6, x5, 20
		memory[1]	= 11111111111111111111111111100111;	//#addi x8, x7, -7
		memory[2]	= 00000000011001000001001000110011;	//#addi x10, x9, 100
		memory[3] = 00000000000100000000000001110011;	//#ebreak
	end

	assign inst_data = memory[inst_addr - 32'h80000000];

endmodule

