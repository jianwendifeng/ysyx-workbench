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
wire [31:0] src1_data_o;
//wire [31:0] src2_data_o;
wire [31:0] imm_wire;

idu idu0(
	
	.id_inst(rom_id_data),
	.src1_data_i(id_reg_src1),
	.opcode_o(opcode_wire),
	.funct3_o(funct3_wire),
	.rd_addr(rd_addr_wire),
	.src1_addr(src1_addr_o),
	.src1_o(src1_data_o),
	//src2_o,
	.imm_o(imm_wire)
);

wire [31:0] ex_data_wire;

RegisterFile #(ADDR_WIDTH = 64, DATA_WIDTH = 64) (
  .clk(clk),
  .wdata(wdata),
  .waddr(waddr),
  .wen(),
  .raddr,
  .rdata
);

exu exu0(
	input [31:0] src1(),
	imm(imm_wire),
	output	[31;0] ex_data(ex_data_wire);
);




endmodule


