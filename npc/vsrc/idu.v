module idu (//#(RESET_VAL = 0) (
	input clk,
	//input rst,
	input [31:0] id_inst,
	input [31:0] id_src1_wdata,
	output reg [6:0] id_op,
	output reg [2:0] id_funct3,
	output reg [31:0] id_src1_rdata,
	output reg [11:0] id_imm
);


	Reg Reg0(
		.clk(clk),
		.wdata(id_src1_wdata),
		.waddr(id_inst[11:7]),
		.wen(1),
		.raddr(id_inst[19:15]),
		.rdata(id_src1_rdata)
	);
	always@(*)begin
		id_op 		= id_inst[6:0];
		id_funct3 	= id_inst[14:12];
		id_imm		= id_inst[31:20];	//imm value
	end
	
endmodule
