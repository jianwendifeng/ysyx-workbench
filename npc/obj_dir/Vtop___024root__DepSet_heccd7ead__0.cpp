// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ top__DOT__idu0__DOT__Reg0__DOT____Vlvbound_h731b7a34__0;
    top__DOT__idu0__DOT__Reg0__DOT____Vlvbound_h731b7a34__0 = 0;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__idu0__DOT__Reg0__DOT__rf__v0;
    __Vdlyvdim0__top__DOT__idu0__DOT__Reg0__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__idu0__DOT__Reg0__DOT__rf__v0;
    __Vdlyvval__top__DOT__idu0__DOT__Reg0__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__idu0__DOT__Reg0__DOT__rf__v0;
    __Vdlyvset__top__DOT__idu0__DOT__Reg0__DOT__rf__v0 = 0;
    // Body
    __Vdlyvset__top__DOT__idu0__DOT__Reg0__DOT__rf__v0 = 0U;
    vlSelf->top__DOT__ifu0__DOT__pc_rom = ((IData)(vlSelf->rst)
                                            ? 0x80000000U
                                            : ((IData)(4U) 
                                               + vlSelf->top__DOT__ifu0__DOT__pc_rom));
    top__DOT__idu0__DOT__Reg0__DOT____Vlvbound_h731b7a34__0 
        = vlSelf->top__DOT__ex_id_src1;
    if ((4U >= (7U & (vlSelf->top__DOT__if_id_pc >> 7U)))) {
        __Vdlyvval__top__DOT__idu0__DOT__Reg0__DOT__rf__v0 
            = top__DOT__idu0__DOT__Reg0__DOT____Vlvbound_h731b7a34__0;
        __Vdlyvset__top__DOT__idu0__DOT__Reg0__DOT__rf__v0 = 1U;
        __Vdlyvdim0__top__DOT__idu0__DOT__Reg0__DOT__rf__v0 
            = (7U & (vlSelf->top__DOT__if_id_pc >> 7U));
    }
    if (__Vdlyvset__top__DOT__idu0__DOT__Reg0__DOT__rf__v0) {
        vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf[__Vdlyvdim0__top__DOT__idu0__DOT__Reg0__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__idu0__DOT__Reg0__DOT__rf__v0;
    }
    vlSelf->top__DOT__if_id_pc = vlSelf->top__DOT__ifu0__DOT__inst_rom0__DOT__memory
        [(0x1fU & vlSelf->top__DOT__ifu0__DOT__pc_rom)];
    vlSelf->top__DOT__ex_id_src1 = ((0x13U == (0x7fU 
                                               & vlSelf->top__DOT__if_id_pc))
                                     ? ((0U == (7U 
                                                & (vlSelf->top__DOT__if_id_pc 
                                                   >> 0xcU)))
                                         ? (((4U >= 
                                              (7U & 
                                               (vlSelf->top__DOT__if_id_pc 
                                                >> 0xfU)))
                                              ? vlSelf->top__DOT__idu0__DOT__Reg0__DOT__rf
                                             [(7U & 
                                               (vlSelf->top__DOT__if_id_pc 
                                                >> 0xfU))]
                                              : 0U) 
                                            + (vlSelf->top__DOT__if_id_pc 
                                               >> 0x14U))
                                         : 0U) : 0U);
    vlSelf->npc_data = vlSelf->top__DOT__ex_id_src1;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
