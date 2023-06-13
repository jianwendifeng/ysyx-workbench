module inst_rom(
	input [31:0] inst_addr,
	output reg [31:0] inst_data
);

	reg [31:0] memory [31:0];
	reg [4:0] memmory_addr;

	initial begin
		//initial inst_reg
		for(int i = 0 ;i <= 28 ; i+=4)begin
			memory[i+0] = 32'b00000000010101000001010100110011;	//#addi x6, x5, 20
			memory[i+1] = 32'b11111111111111111111111111100111;	//#addi x8, x7, -7
			memory[i+2] = 32'b00000000011001000001001000110011;	//#addi x10, x9, 100\
			memory[i+2] = 32'b00000000011001000001001000110011;	//#addi x10, x9, 100
		end
	end

	always @ (*)begin
		memmory_addr = inst_addr - 32'h80000000;
	 	inst_data = memory[memmory_addr];
 end

endmodule
