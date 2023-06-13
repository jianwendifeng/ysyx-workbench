// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+76,"clk", false,-1);
    tracep->declBit(c+77,"rst", false,-1);
    tracep->declBus(c+78,"npc_data", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+76,"clk", false,-1);
    tracep->declBit(c+77,"rst", false,-1);
    tracep->declBus(c+78,"npc_data", false,-1, 31,0);
    tracep->declBus(c+35,"if_id_pc", false,-1, 31,0);
    tracep->declBus(c+36,"id_ex_op", false,-1, 6,0);
    tracep->declBus(c+37,"id_ex_funct3", false,-1, 14,12);
    tracep->declBus(c+38,"id_ex_imm", false,-1, 31,20);
    tracep->declBus(c+39,"id_ex_src1", false,-1, 31,0);
    tracep->declBus(c+40,"ex_id_src1", false,-1, 31,0);
    tracep->pushNamePrefix("exu0 ");
    tracep->declBus(c+36,"ex_op", false,-1, 6,0);
    tracep->declBus(c+39,"ex_src1", false,-1, 31,0);
    tracep->declBus(c+38,"ex_imm", false,-1, 11,0);
    tracep->declBus(c+37,"ex_funct3", false,-1, 14,12);
    tracep->declBus(c+40,"ex_result", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBit(c+76,"clk", false,-1);
    tracep->declBus(c+35,"id_inst", false,-1, 31,0);
    tracep->declBus(c+40,"id_src1_wdata", false,-1, 31,0);
    tracep->declBus(c+36,"id_op", false,-1, 6,0);
    tracep->declBus(c+37,"id_funct3", false,-1, 2,0);
    tracep->declBus(c+39,"id_src1_rdata", false,-1, 31,0);
    tracep->declBus(c+38,"id_imm", false,-1, 11,0);
    tracep->pushNamePrefix("Reg0 ");
    tracep->declBus(c+79,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+80,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+76,"clk", false,-1);
    tracep->declBus(c+40,"wdata", false,-1, 31,0);
    tracep->declBus(c+41,"waddr", false,-1, 4,0);
    tracep->declBit(c+81,"wen", false,-1);
    tracep->declBus(c+42,"raddr", false,-1, 4,0);
    tracep->declBus(c+39,"rdata", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+43+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+76,"clk", false,-1);
    tracep->declBit(c+77,"rst", false,-1);
    tracep->declBus(c+35,"ifu_out", false,-1, 31,0);
    tracep->declBus(c+75,"pc_rom", false,-1, 31,0);
    tracep->pushNamePrefix("inst_rom0 ");
    tracep->declBus(c+75,"inst_addr", false,-1, 31,0);
    tracep->declBus(c+35,"inst_data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+2+i*1,"memory", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+34,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pc0 ");
    tracep->declBus(c+82,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+76,"clk", false,-1);
    tracep->declBit(c+77,"rst", false,-1);
    tracep->declBus(c+75,"pc_out", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[0]),32);
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[1]),32);
    bufp->fullIData(oldp+4,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[2]),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[3]),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[4]),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[5]),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[6]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[7]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[8]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[9]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[10]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[11]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[12]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[13]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[14]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[15]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[16]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[17]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[18]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[19]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[20]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[21]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[22]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[23]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[24]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[25]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[26]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[27]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[28]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[29]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[30]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory[31]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__if_id_pc),32);
    bufp->fullCData(oldp+36,((0x7fU & vlSelf->top__DOT__if_id_pc)),7);
    bufp->fullCData(oldp+37,((7U & (vlSelf->top__DOT__if_id_pc 
                                    >> 0xcU))),3);
    bufp->fullSData(oldp+38,((vlSelf->top__DOT__if_id_pc 
                              >> 0x14U)),12);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf
                             [(0x1fU & (vlSelf->top__DOT__if_id_pc 
                                        >> 0xfU))]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__ex_id_src1),32);
    bufp->fullCData(oldp+41,((0x1fU & (vlSelf->top__DOT__if_id_pc 
                                       >> 7U))),5);
    bufp->fullCData(oldp+42,((0x1fU & (vlSelf->top__DOT__if_id_pc 
                                       >> 0xfU))),5);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[0]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[1]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[2]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[3]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[4]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[5]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[6]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[7]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[8]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[9]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[10]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[11]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[12]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[13]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[14]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[15]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[16]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[17]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[18]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[19]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[20]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[21]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[22]),32);
    bufp->fullIData(oldp+66,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[23]),32);
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[24]),32);
    bufp->fullIData(oldp+68,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[25]),32);
    bufp->fullIData(oldp+69,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[26]),32);
    bufp->fullIData(oldp+70,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[27]),32);
    bufp->fullIData(oldp+71,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[28]),32);
    bufp->fullIData(oldp+72,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[29]),32);
    bufp->fullIData(oldp+73,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[30]),32);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[31]),32);
    bufp->fullIData(oldp+75,(vlSelf->top__DOT__ifu0__DOT__pc_rom),32);
    bufp->fullBit(oldp+76,(vlSelf->clk));
    bufp->fullBit(oldp+77,(vlSelf->rst));
    bufp->fullIData(oldp+78,(vlSelf->npc_data),32);
    bufp->fullIData(oldp+79,(5U),32);
    bufp->fullIData(oldp+80,(0x20U),32);
    bufp->fullBit(oldp+81,(1U));
    bufp->fullIData(oldp+82,(0x80000000U),32);
}
