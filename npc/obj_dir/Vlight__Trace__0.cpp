// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlight__Syms.h"


void Vlight___024root__trace_chg_sub_0(Vlight___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vlight___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root__trace_chg_top_0\n"); );
    // Init
    Vlight___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlight___024root*>(voidSelf);
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vlight___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vlight___024root__trace_chg_sub_0(Vlight___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->rst));
    bufp->chgSData(oldp+2,(vlSelf->led),16);
    bufp->chgIData(oldp+3,(vlSelf->light__DOT__count),32);
}

void Vlight___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlight___024root__trace_cleanup\n"); );
    // Init
    Vlight___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlight___024root*>(voidSelf);
    Vlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
