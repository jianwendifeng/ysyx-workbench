module idu #(RESET_VAL = 0) (
	//input clk,
	//input rst,
	//input [63:0] id_addr,
	input [63:0] id_inst,
	input [63:0] src1_data_i,
	output reg [6:0] opcode_o,
	//output reg [11-7:7-7] id_rd,
	output reg [14-12:12-12] funct3_o,
	output reg [31:0] rd_addr,
	output reg [63:0] src1_addr,
	output reg [63:0] src1_data_o,
	output reg [31-20:20-20] imm_o
);
	assign opcode_o 	= id_inst[6:0];
	assign funct3_o 	= id_inst[14:12];
	assign imm_o			= id_inst[31:20];	//imm value
	assign rd_addr		= id_inst[11:7];
	assign src1_addr	= id_inst[19:15];
	assign src1_data_o	= src1_data_i;

	/*always @(posedge clk) begin
		if(rst) 
			begin 
				id_opcode <= RESET_VAL;
				id_funct3 <= RESET_VAL;
				id_src1		<= RESET_VAL;
				id_imm		<= RESET_VAL;
			end
		else 
			begin
				id_opcode <= id_data[6:0];
				id_funct3 <= id_data[14:12];
				id_src1		<= ;	//src1 value
				id_imm		<= id_in[31:20];	//imm value
			end
	end	*/

endmodule
