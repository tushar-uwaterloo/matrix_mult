// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmat_vect_mult2.h for the primary calling header

#include "Vmat_vect_mult2.h"   // For This
#include "Vmat_vect_mult2__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmat_vect_mult2) {
    Vmat_vect_mult2__Syms* __restrict vlSymsp = __VlSymsp = new Vmat_vect_mult2__Syms(this, name());
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmat_vect_mult2::__Vconfigure(Vmat_vect_mult2__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmat_vect_mult2::~Vmat_vect_mult2() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmat_vect_mult2::eval() {
    Vmat_vect_mult2__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vmat_vect_mult2::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vmat_vect_mult2::_eval_initial_loop(Vmat_vect_mult2__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vmat_vect_mult2::_sequent__TOP__1(Vmat_vect_mult2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::_sequent__TOP__1\n"); );
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v0,0,0);
    VL_SIG8(__Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v1,7,0);
    VL_SIG8(__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v1,0,0);
    VL_SIG8(__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v2,0,0);
    VL_SIG8(__Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v3,7,0);
    VL_SIG8(__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v3,0,0);
    VL_SIG8(__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v4,0,0);
    VL_SIG8(__Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v5,7,0);
    VL_SIG8(__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v5,0,0);
    VL_SIG8(__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v6,0,0);
    VL_SIG8(__Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v7,7,0);
    VL_SIG8(__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v7,0,0);
    VL_SIG8(__Vdly__mat_vect_mult2__DOT__slice,1,0);
    VL_SIG8(__Vdly__m_axis_tvalid,0,0);
    VL_SIG8(__Vdly__mat_vect_mult2__DOT__count,1,0);
    //char	__VpadToAlign19[1];
    VL_SIG(__Vdly__m_axis_tdata,17,0);
    // Body
    __Vdly__m_axis_tvalid = vlTOPp->m_axis_tvalid;
    __Vdly__m_axis_tdata = vlTOPp->m_axis_tdata;
    __Vdly__mat_vect_mult2__DOT__slice = vlTOPp->mat_vect_mult2__DOT__slice;
    __Vdly__mat_vect_mult2__DOT__count = vlTOPp->mat_vect_mult2__DOT__count;
    __Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v0 = 0U;
    __Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v1 = 0U;
    __Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v2 = 0U;
    __Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v3 = 0U;
    __Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v4 = 0U;
    __Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v5 = 0U;
    __Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v6 = 0U;
    __Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v7 = 0U;
    // ALWAYS at mat_vect_mult2.v:95
    if (vlTOPp->areset) {
	__Vdly__m_axis_tvalid = 0U;
    } else {
	if (vlTOPp->m_axis_tready) {
	    __Vdly__m_axis_tvalid = 0U;
	} else {
	    if (((IData)(vlTOPp->s_axis_tlast) & (IData)(vlTOPp->s_axis_tready))) {
		__Vdly__m_axis_tvalid = 1U;
	    }
	}
    }
    // ALWAYS at mat_vect_mult2.v:106
    if (vlTOPp->areset) {
	vlTOPp->m_axis_tlast = 0U;
    } else {
	if (vlTOPp->m_axis_tready) {
	    vlTOPp->m_axis_tlast = 0U;
	} else {
	    if ((((IData)(vlTOPp->s_axis_tlast) & (IData)(vlTOPp->s_axis_tready)) 
		 & (3U == (IData)(vlTOPp->mat_vect_mult2__DOT__count)))) {
		vlTOPp->m_axis_tlast = 1U;
	    }
	}
    }
    // ALWAYS at mat_vect_mult2.v:67
    if (vlTOPp->areset) {
	__Vdly__m_axis_tdata = 0U;
    } else {
	if (((IData)(vlTOPp->s_axis_tvalid) & (IData)(vlTOPp->s_axis_tready))) {
	    __Vdly__m_axis_tdata = (0x3ffffU & (vlTOPp->m_axis_tdata 
						+ ((IData)(vlTOPp->s_axis_tdata) 
						   * 
						   vlTOPp->mat_vect_mult2__DOT__inp_vect_lat
						   [vlTOPp->mat_vect_mult2__DOT__slice])));
	} else {
	    if (((IData)(vlTOPp->m_axis_tvalid) & (IData)(vlTOPp->m_axis_tready))) {
		__Vdly__m_axis_tdata = 0U;
	    }
	}
    }
    // ALWAYS at mat_vect_mult2.v:81
    if (vlTOPp->areset) {
	__Vdly__mat_vect_mult2__DOT__slice = 0U;
    } else {
	if ((((IData)(vlTOPp->s_axis_tvalid) & (IData)(vlTOPp->s_axis_tready)) 
	     & (IData)(vlTOPp->s_axis_tlast))) {
	    __Vdly__mat_vect_mult2__DOT__slice = 0U;
	} else {
	    if (((IData)(vlTOPp->s_axis_tvalid) & (IData)(vlTOPp->s_axis_tready))) {
		__Vdly__mat_vect_mult2__DOT__slice 
		    = (3U & ((IData)(1U) + (IData)(vlTOPp->mat_vect_mult2__DOT__slice)));
	    }
	}
    }
    // ALWAYS at mat_vect_mult2.v:118
    if (vlTOPp->areset) {
	__Vdly__mat_vect_mult2__DOT__count = 0U;
    } else {
	if (((IData)(vlTOPp->s_axis_tlast) & (IData)(vlTOPp->s_axis_tready))) {
	    __Vdly__mat_vect_mult2__DOT__count = (3U 
						  & ((3U 
						      == (IData)(vlTOPp->mat_vect_mult2__DOT__count))
						      ? 0U
						      : 
						     ((IData)(1U) 
						      + (IData)(vlTOPp->mat_vect_mult2__DOT__count))));
	}
    }
    // ALWAYS at mat_vect_mult2.v:42
    if (vlTOPp->areset) {
	__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v0 = 1U;
    } else {
	__Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v1 
	    = vlTOPp->mat_vect_mult2__DOT__inp_vect_lat
	    [0U];
	__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v1 = 1U;
    }
    // ALWAYS at mat_vect_mult2.v:42
    if (vlTOPp->areset) {
	__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v2 = 1U;
    } else {
	__Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v3 
	    = vlTOPp->mat_vect_mult2__DOT__inp_vect_lat
	    [1U];
	__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v3 = 1U;
    }
    // ALWAYS at mat_vect_mult2.v:42
    if (vlTOPp->areset) {
	__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v4 = 1U;
    } else {
	__Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v5 
	    = vlTOPp->mat_vect_mult2__DOT__inp_vect_lat
	    [2U];
	__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v5 = 1U;
    }
    // ALWAYS at mat_vect_mult2.v:42
    if (vlTOPp->areset) {
	__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v6 = 1U;
    } else {
	__Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v7 
	    = vlTOPp->mat_vect_mult2__DOT__inp_vect_lat
	    [3U];
	__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v7 = 1U;
    }
    vlTOPp->m_axis_tdata = __Vdly__m_axis_tdata;
    vlTOPp->mat_vect_mult2__DOT__slice = __Vdly__mat_vect_mult2__DOT__slice;
    vlTOPp->mat_vect_mult2__DOT__count = __Vdly__mat_vect_mult2__DOT__count;
    // ALWAYSPOST at mat_vect_mult2.v:45
    if (__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v0) {
	vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[0U] = 0U;
    }
    if (__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v1) {
	vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[0U] 
	    = __Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v1;
    }
    if (__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v2) {
	vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[1U] = 0U;
    }
    if (__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v3) {
	vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[1U] 
	    = __Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v3;
    }
    if (__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v4) {
	vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[2U] = 0U;
    }
    if (__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v5) {
	vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[2U] 
	    = __Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v5;
    }
    if (__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v6) {
	vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[3U] = 0U;
    }
    if (__Vdlyvset__mat_vect_mult2__DOT__inp_vect_reg__v7) {
	vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[3U] 
	    = __Vdlyvval__mat_vect_mult2__DOT__inp_vect_reg__v7;
    }
    // ALWAYS at mat_vect_mult2.v:55
    vlTOPp->s_axis_tready = ((~ (IData)(vlTOPp->areset)) 
			     & (((~ (IData)(vlTOPp->m_axis_tvalid)) 
				 & (IData)(vlTOPp->s_axis_tvalid)) 
				& (~ (IData)(vlTOPp->s_axis_tlast))));
    vlTOPp->m_axis_tvalid = __Vdly__m_axis_tvalid;
    vlTOPp->inp_vect_rdy = (1U & ((0U == (IData)(vlTOPp->mat_vect_mult2__DOT__count))
				   ? (IData)(vlTOPp->s_axis_tready)
				   : 0U));
}

void Vmat_vect_mult2::_settle__TOP__2(Vmat_vect_mult2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::_settle__TOP__2\n"); );
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->inp_vect_rdy = (1U & ((0U == (IData)(vlTOPp->mat_vect_mult2__DOT__count))
				   ? (IData)(vlTOPp->s_axis_tready)
				   : 0U));
    vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[0U] = 
	((((IData)(vlTOPp->inp_vect_rdy) & (IData)(vlTOPp->inp_vect_valid)) 
	  & (0U == (IData)(vlTOPp->mat_vect_mult2__DOT__slice)))
	  ? (IData)(vlTOPp->inp_vect) : vlTOPp->mat_vect_mult2__DOT__inp_vect_reg
	 [0U]);
    vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[1U] = 
	((((IData)(vlTOPp->inp_vect_rdy) & (IData)(vlTOPp->inp_vect_valid)) 
	  & (1U == (IData)(vlTOPp->mat_vect_mult2__DOT__slice)))
	  ? (IData)(vlTOPp->inp_vect) : vlTOPp->mat_vect_mult2__DOT__inp_vect_reg
	 [1U]);
    vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[2U] = 
	((((IData)(vlTOPp->inp_vect_rdy) & (IData)(vlTOPp->inp_vect_valid)) 
	  & (2U == (IData)(vlTOPp->mat_vect_mult2__DOT__slice)))
	  ? (IData)(vlTOPp->inp_vect) : vlTOPp->mat_vect_mult2__DOT__inp_vect_reg
	 [2U]);
    vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[3U] = 
	((((IData)(vlTOPp->inp_vect_rdy) & (IData)(vlTOPp->inp_vect_valid)) 
	  & (3U == (IData)(vlTOPp->mat_vect_mult2__DOT__slice)))
	  ? (IData)(vlTOPp->inp_vect) : vlTOPp->mat_vect_mult2__DOT__inp_vect_reg
	 [3U]);
}

VL_INLINE_OPT void Vmat_vect_mult2::_combo__TOP__3(Vmat_vect_mult2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::_combo__TOP__3\n"); );
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[0U] = 
	((((IData)(vlTOPp->inp_vect_rdy) & (IData)(vlTOPp->inp_vect_valid)) 
	  & (0U == (IData)(vlTOPp->mat_vect_mult2__DOT__slice)))
	  ? (IData)(vlTOPp->inp_vect) : vlTOPp->mat_vect_mult2__DOT__inp_vect_reg
	 [0U]);
    vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[1U] = 
	((((IData)(vlTOPp->inp_vect_rdy) & (IData)(vlTOPp->inp_vect_valid)) 
	  & (1U == (IData)(vlTOPp->mat_vect_mult2__DOT__slice)))
	  ? (IData)(vlTOPp->inp_vect) : vlTOPp->mat_vect_mult2__DOT__inp_vect_reg
	 [1U]);
    vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[2U] = 
	((((IData)(vlTOPp->inp_vect_rdy) & (IData)(vlTOPp->inp_vect_valid)) 
	  & (2U == (IData)(vlTOPp->mat_vect_mult2__DOT__slice)))
	  ? (IData)(vlTOPp->inp_vect) : vlTOPp->mat_vect_mult2__DOT__inp_vect_reg
	 [2U]);
    vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[3U] = 
	((((IData)(vlTOPp->inp_vect_rdy) & (IData)(vlTOPp->inp_vect_valid)) 
	  & (3U == (IData)(vlTOPp->mat_vect_mult2__DOT__slice)))
	  ? (IData)(vlTOPp->inp_vect) : vlTOPp->mat_vect_mult2__DOT__inp_vect_reg
	 [3U]);
}

void Vmat_vect_mult2::_eval(Vmat_vect_mult2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::_eval\n"); );
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->aclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__aclk))) 
	 | ((IData)(vlTOPp->areset) & (~ (IData)(vlTOPp->__Vclklast__TOP__areset))))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__aclk = vlTOPp->aclk;
    vlTOPp->__Vclklast__TOP__areset = vlTOPp->areset;
}

void Vmat_vect_mult2::_eval_initial(Vmat_vect_mult2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::_eval_initial\n"); );
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmat_vect_mult2::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::final\n"); );
    // Variables
    Vmat_vect_mult2__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmat_vect_mult2::_eval_settle(Vmat_vect_mult2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::_eval_settle\n"); );
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vmat_vect_mult2::_change_request(Vmat_vect_mult2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::_change_request\n"); );
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void Vmat_vect_mult2::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::_ctor_var_reset\n"); );
    // Body
    aclk = VL_RAND_RESET_I(1);
    areset = VL_RAND_RESET_I(1);
    inp_vect = VL_RAND_RESET_I(8);
    inp_vect_valid = VL_RAND_RESET_I(1);
    inp_vect_rdy = VL_RAND_RESET_I(1);
    s_axis_tdata = VL_RAND_RESET_I(8);
    s_axis_tvalid = VL_RAND_RESET_I(1);
    s_axis_tlast = VL_RAND_RESET_I(1);
    s_axis_tready = VL_RAND_RESET_I(1);
    m_axis_tdata = VL_RAND_RESET_I(18);
    m_axis_tvalid = VL_RAND_RESET_I(1);
    m_axis_tlast = VL_RAND_RESET_I(1);
    m_axis_tready = VL_RAND_RESET_I(1);
    mat_vect_mult2__DOT__count = VL_RAND_RESET_I(2);
    mat_vect_mult2__DOT__slice = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    mat_vect_mult2__DOT__inp_vect_lat[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    mat_vect_mult2__DOT__inp_vect_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    __Vclklast__TOP__aclk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__areset = VL_RAND_RESET_I(1);
}

void Vmat_vect_mult2::_configure_coverage(Vmat_vect_mult2__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    Vmat_vect_mult2::_configure_coverage\n"); );
}
