/* verilator lint_off UNUSEDSIGNAL */ //inst_addr only use [4:0] bit,[31:5] haven't use
module inst_rom(
	input [31:0] inst_addr,
	output reg [31:0] inst_data
);

	reg [31:0] memory [31:0];

	initial begin
		//initial inst_reg
		for(int i = 0 ;i <= 28 ; i+=4)begin
			memory[i+0] = 32'b000000000101010000000	1010	0010011;	//#addi x6, x5, 20
			memory[i+1] = 32'b11111111111111111111111111100111;	//#addi x8, x7, -7
			memory[i+2] = 32'b00000000011001000001001000110011;	//#addi x10, x9, 100\
			memory[i+2] = 32'b00000000011001000001001000110011;	//#addi x10, x9, 100
		end
	end

	always @ (*)begin
	 	inst_data = memory[inst_addr];
 end

endmodule
