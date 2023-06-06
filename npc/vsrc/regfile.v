module RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
  input 
);
  reg [DATA_WIDTH-1:0] rf [ADDR_WIDTH-1:0];
  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end

  initial begin
    rf[0] = 0;  // 初始化 0 号寄存器的值为 0
    for(int i = 0;i < 32 ; i++){
      rf[i] = i;
    }
  end

endmodule
