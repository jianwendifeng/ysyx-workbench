module top(
	input clk,
	input rst,
	output [63:0] npc_data
);


wire [63:0] pc_id;
pc pc0(
	.clk(clk),
 	.rst(rst),
  .pc_in(pc_id),
 	.pc_out(pc_id)
);

wire [31:0] pc_rom_inst;
wire [31:0] id_reg_data;
wire [31:0] rom_id_data;

inst_rom inst_rom0(
	.inst_addr(pc_rom_inst),
	.inst_data(rom_id_data)
);

wire [31:0] id_reg_src1;
//wire [31:0] id_reg_src2;
wire [6:0] opcode_wire;
wire [2:0] funct3_wire;
wire [31:0] src1_data_wire;
//wire [31:0] src2_data_wire;
wire [31:0] rd_addr_wire;
wire [31:0] src1_addr_wire;
wire [31:0] src1_data_o_wire;
//wire [31:0] src2_data_o;
wire [31:0] imm_wire;

idu idu0(
	//.clk(clk),
	//.rst(rst),
	.id_inst(rom_id_data),
	.src1_data_i(id_reg_src1),
	.opcode_o(opcode_wire),
	.funct3_o(funct3_wire),
	.rd_addr(rd_addr_wire),
	.src1_addr(src1_addr_o_wire),
	.src1_data_o(src1_data_o),
	//src2_o,
	.imm_o(imm_wire)
);

wire [31:0] ex_data_wire;

Reg Reg0 (
  .clk(clk),
  .wdata(ex_data_wire),
  .waddr(rd_addr_wire),
  .wen(1),
  .raddr(src1_addr_o_wire),
  .rdata(id_reg_src1)
);

exu exu0(
	.src1(src1_data_o),
	.imm(imm_wire),
	.ex_data(ex_data_wire)
);

assign npc_data = ex_data_wire;


endmodule


