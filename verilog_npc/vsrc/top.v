module top(
	input clk,
	input rst,
	output [31:0] npc_data
);

wire [31:0] if_id_pc;

ifu ifu0(
	.clk(clk),
	.rst(rst),
	.ifu_out(if_id_pc)
);

wire [6:0] id_ex_op;
wire [14:12] id_ex_funct3;
wire [31:20] id_ex_imm;
wire [31:0] id_ex_src1;
wire [31:0] ex_id_src1;

idu idu0(
	.clk(clk),
	.id_inst(if_id_pc),
	.id_op(id_ex_op),
	.id_funct3(id_ex_funct3),
	.id_src1_rdata(id_ex_src1),
	.id_src1_wdata(ex_id_src1),
	.id_imm(id_ex_imm)
);


exu exu0(
	.ex_op(id_ex_op),
	.ex_src1(id_ex_src1),
	.ex_funct3(id_ex_funct3),
	.ex_imm(id_ex_imm),
	.ex_result(ex_id_src1)
);

assign npc_data = ex_id_src1;


endmodule


