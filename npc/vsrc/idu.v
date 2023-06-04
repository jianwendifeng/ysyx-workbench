module RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
	output [DATA_WIDRH-1:0] rdata
);
  reg [DATA_WIDTH-1:0] rf [ADDR_WIDTH-1:0];
  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end

	
endmodule


module idu #(RESET_VAL = 0) (
	input clk,
	input rst,
	//input [63:0] id_addr,
	input [63:0] id_data,
	output reg [6:0] id_opcode,
	//output reg [11-7:7-7] id_rd,
	output reg [14-12:12-12] id_funct3,
	output reg [63:0] id_src1,
	output reg [31-20:20-20] id_imm
);

	wire [63:0] id_in_data;

	RegisterFile #(64,64) i0(clk,id_data,id_addr,1'b1);	//寄存器堆

	always @(posedge clk) begin
		if (rst) 
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
				id_src1		<=	RegisterFile #(64,64) i0(clk,0,id_data[19:15]);	//src1 value
				id_imm		<= id_in[31:20];	//imm value
			end
	end	

endmodule
