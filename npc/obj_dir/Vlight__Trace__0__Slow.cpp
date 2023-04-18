// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlight__Syms.h"


VL_ATTR_COLD void Vlight___024root__trace_init_sub__TOP__0(Vlight___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBus(c+3,"led", false,-1, 15,0);
    tracep->pushNamePrefix("light ");
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBus(c+3,"led", false,-1, 15,0);
    tracep->declBus(c+4,"count", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vlight___024root__trace_init_top(Vlight___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root__trace_init_top\n"); );
    // Body
    Vlight___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vlight___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vlight___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vlight___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vlight___024root__trace_register(Vlight___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vlight___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vlight___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vlight___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vlight___024root__trace_full_sub_0(Vlight___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vlight___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root__trace_full_top_0\n"); );
    // Init
    Vlight___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlight___024root*>(voidSelf);
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vlight___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vlight___024root__trace_full_sub_0(Vlight___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->rst));
    bufp->fullSData(oldp+3,(vlSelf->led),16);
    bufp->fullIData(oldp+4,(vlSelf->light__DOT__count),32);
}
