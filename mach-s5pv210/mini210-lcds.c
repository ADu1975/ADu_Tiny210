/*
 * linux/arch/arm/mach-s5pv210/mini210-lcds.c
 *
 * Copyright (c) 2011 FriendlyARM (www.arm9.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/gpio.h>

#include <plat/fb.h>
#include <plat/ctouch.h>
#include <mach/gpio.h>
#include <mach/regs-gpio.h>
#include <mach/option.h>

#include <../../../drivers/video/samsung/s3cfb.h>


#if YTS800SLAC
static struct s3cfb_lcd wvga_w101 = {
	.width = 800,
        .height = 600,
        .bpp = 32,
        .freq = 40,

        .timing = {
                .h_fp = 16,
                .h_bp = 46,
                .h_sw = 20,
                .v_fp = 12,
                .v_fpe = 1,
                .v_bp = 23,
                .v_bpe = 1,
                .v_sw = 20,
	
        },

        .polarity = {
                .rise_vclk = 0,
                .inv_hsync = 1,
                .inv_vsync = 1,
                .inv_vden = 0,
        },
};
#elif YTS800VLAA
static struct s3cfb_lcd wvga_w101 = {
	.width = 1024,
        .height = 768,
        .bpp = 32,
        .freq = 45,

        .timing = {
                .h_fp = 160,
                .h_bp = 160,
                .h_sw = 140,
                .v_fp = 15,
                .v_fpe = 1,
                .v_bp = 23,
                .v_bpe = 1,
                .v_sw = 20,
	
        },

        .polarity = {
                .rise_vclk = 0,
                .inv_hsync = 1,
                .inv_vsync = 1,
                .inv_vden = 0,
        },
};
#elif YTCA10TLAA_01_100C
static struct s3cfb_lcd wvga_w101 = {
	.width = 1024,
        .height = 600,
        .bpp = 32,
        .freq = 65,

        .timing = {
                .h_fp = 230,
                .h_bp = 90,
                .h_sw = 370,
                .v_fp = 25,
                .v_fpe = 1,
                .v_bp = 13,
                .v_bpe = 1,
                .v_sw = 10,
	
        },

        .polarity = {
                .rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
        },
};
#elif YTSC10VLAA
static struct s3cfb_lcd wvga_w101 = {
	.width = 1024,
        .height = 768,
        .bpp = 32,
        .freq = 65,

        .timing = {
                .h_fp = 48,
                .h_bp = 240,
                .h_sw = 32,
                .v_fp = 3,
                .v_fpe = 1,
                .v_bp = 23,
                .v_bpe = 1,
                .v_sw = 12,
	
        },

        .polarity = {
                .rise_vclk = 0,
                .inv_hsync = 1,
                .inv_vsync = 1,
                .inv_vden = 0,
        },
};
#elif YTS800VLAF
static struct s3cfb_lcd wvga_w101 = {
	.width = 1024,
        .height = 768,
        .bpp = 32,
        .freq = 65,

        .timing = {
                .h_fp = 160,
                .h_bp = 160,
                .h_sw = 140,
                .v_fp = 15,
                .v_fpe = 1,
                .v_bp = 23,
                .v_bpe = 1,
                .v_sw = 20,
	
        },

        .polarity = {
                .rise_vclk = 0,
                .inv_hsync = 1,
                .inv_vsync = 1,
                .inv_vden = 0,
        },
};
#elif YTS700TLAG
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp = 40,
		.h_bp = 40,
		.h_sw = 120,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 10,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS700TLAF_04_102C
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp = 40,
		.h_bp = 40,
		.h_sw = 120,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 10,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#elif YTS700TLAI
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 51,

	.timing = {
		.h_fp = 40,
		.h_bp = 320,
		.h_sw = 120,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 35,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS700TLAL_01_100C
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 51,

	.timing = {
		.h_fp = 40,
		.h_bp = 320,
		.h_sw = 120,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 35,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTCA10TLAB_01_100C
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 51,

	.timing = {
		.h_fp = 40,
		.h_bp = 320,
		.h_sw = 120,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 35,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS700TLAL_02_100C
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 51,

	.timing = {
		.h_fp = 40,
		.h_bp = 320,
		.h_sw = 120,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 35,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS700TLAN_01_100C
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 36,
		.h_bp = 60,
		.h_sw = 30,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 11,
		.v_bpe = 1,
		.v_sw = 0x10,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTC700TLAC
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 36,
		.h_bp = 60,
		.h_sw = 30,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 11,
		.v_bpe = 1,
		.v_sw = 0x10,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#elif YTS700TLAM
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 0x320,
		.h_bp = 0xa8,
		.h_sw = 0x2a,
		.v_fp = 30,
		.v_fpe = 1,
		.v_bp = 0x02,
		.v_bpe = 1,
		.v_sw = 0x10,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 0,
		.inv_vsync = 0,
		.inv_vden = 1,
	},
};
#else
static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp = 40,
		.h_bp = 40,
		.h_sw = 120,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 10,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#endif


/* s3cfb configs for supported LCD */

static struct s3cfb_lcd wvga_w50 = {
	.width= 800,
	.height = 480,
	.p_width = 108,
	.p_height = 64,
	.bpp = 32,
	.freq = 75,

	.timing = {
		.h_fp = 40,
		.h_bp = 40,
		.h_sw = 48,
		.v_fp = 20,
		.v_fpe = 1,
		.v_bp = 20,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_a70 = {
	.width = 800,
	.height = 480,
	.p_width = 152,
	.p_height = 90,
	.bpp = 32,
	.freq = 85,

	.timing = {
		.h_fp = 40,
		.h_bp = 40,
		.h_sw = 48,
		.v_fp = 17,
		.v_fpe = 1,
		.v_bp = 29,
		.v_bpe = 1,
		.v_sw = 24,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#if YTS800RLAC
static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 88,
		.h_bp = 40,
		.h_sw = 48,
		.v_fp = 16,
		.v_fpe = 1,
		.v_bp = 29,
		.v_bpe = 1,
		.v_sw = 3,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS700RLAB
static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 30,

	.timing = {
		.h_fp = 80,
		.h_bp = 36,
		.h_sw = 10,
		.v_fp = 22,
		.v_fpe = 1,
		.v_bp = 15,
		.v_bpe = 1,
		.v_sw = 8,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS500RLAE
static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 30,

	.timing = {
		.h_fp = 210,
		.h_bp = 46,
		.h_sw = 10,
		.v_fp = 22,
		.v_fpe = 1,
		.v_bp = 23,
		.v_bpe = 1,
		.v_sw = 10,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden =  0,
	},
};

#elif YTS700RLAU_01_101C
static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 85,

	.timing = {
		.h_fp = 210,
		.h_bp = 46,
		.h_sw = 10,
		.v_fp = 22,
		.v_fpe = 1,
		.v_bp = 23,
		.v_bpe = 1,
		.v_sw = 10,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden =  0,
	},
};

#elif YTS500RLAQ_02_100C
static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp = 40,
		.h_bp = 88,
		.h_sw = 48,
		.v_fp = 13,
		.v_fpe = 1,
		.v_bp = 32,
		.v_bpe = 1,
		.v_sw = 3,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS700RLAT
static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 30,

	.timing = {
		.h_fp = 210,
		.h_bp = 46,
		.h_sw = 4,
		.v_fp = 22,
		.v_fpe = 1,
		.v_bp = 23,
		.v_bpe = 1,
		.v_sw = 4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS700RLAT_MTP700_025
static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp = 210,
		.h_bp = 46,
		.h_sw = 4,
		.v_fp = 22,
		.v_fpe = 1,
		.v_bp = 23,
		.v_bpe = 1,
		.v_sw = 4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS800RLAD
static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 55,

	.timing = {
		.h_fp = 80,
		.h_bp = 36,
		.h_sw = 10,
		.v_fp = 1,
		.v_fpe = 1,
		.v_bp = 15,
		.v_bpe = 1,
		.v_sw = 8,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTS430KLAD
static struct s3cfb_lcd wvga_s70 = {
	.width = 480,
	.height = 800,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 55,

	.timing = {
		.h_fp = 46,
		.h_bp = 44,
		.h_sw = 4,
		.v_fp = 9,
		.v_fpe = 1,
		.v_bp = 16,
		.v_bpe = 1,
		.v_sw = 8,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#elif YTS430KLAE
static struct s3cfb_lcd wvga_s70 = {
	.width = 480,
	.height = 800,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 80,

	.timing = {
		.h_fp = 10,
		.h_bp = 10,
		.h_sw = 5,
		.v_fp = 4,
		.v_fpe = 1,
		.v_bp = 4,
		.v_bpe = 1,
		.v_sw = 4,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 1,
	},
};
#else
static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 80,
		.h_bp = 36,
		.h_sw = 10,
		.v_fp = 22,
		.v_fpe = 1,
		.v_bp = 15,
		.v_bpe = 1,
		.v_sw = 8,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#endif

#if YTS430ILAC
static struct s3cfb_lcd wvga_h43 = {
	.width = 480,
	.height = 272,
	.p_width = 96,
	.p_height = 54,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp =  5,
		.h_bp = 40,
		.h_sw =  2,
		.v_fp =  8,
		.v_fpe = 1,
		.v_bp =  8,
		.v_bpe = 1,
		.v_sw =  2,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#elif YTS430ILAK_01_101C
static struct s3cfb_lcd wvga_h43 = {
	.width = 480,
	.height = 272,
	.p_width = 96,
	.p_height = 54,
	.bpp = 32,
	.freq = 30,

	.timing = {
		.h_fp =  8,
		.h_bp = 43,
		.h_sw =  4,
		.v_fp =  8,
		.v_fpe = 1,
		.v_bp =  12,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#elif YTS430ILAK_02_100C
static struct s3cfb_lcd wvga_h43 = {
	.width = 480,
	.height = 272,
	.p_width = 96,
	.p_height = 54,
	.bpp = 32,
	.freq = 30,

	.timing = {
		.h_fp =  8,
		.h_bp = 43,
		.h_sw =  4,
		.v_fp =  8,
		.v_fpe = 1,
		.v_bp =  12,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTC430ILAG_03_101C
static struct s3cfb_lcd wvga_h43 = {
	.width = 480,
	.height = 272,
	.p_width = 96,
	.p_height = 54,
	.bpp = 32,
	.freq = 80,

	.timing = {
		.h_fp =  8,
		.h_bp = 43,
		.h_sw =  4,
		.v_fp =  8,
		.v_fpe = 1,
		.v_bp =  12,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#elif YTC430ILAG_03_100C
static struct s3cfb_lcd wvga_h43 = {
	.width = 480,
	.height = 272,
	.p_width = 96,
	.p_height = 54,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp =  8,
		.h_bp = 43,
		.h_sw =  4,
		.v_fp =  8,
		.v_fpe = 1,
		.v_bp =  12,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#else
static struct s3cfb_lcd wvga_h43 = {
	.width = 480,
	.height = 272,
	.p_width = 96,
	.p_height = 54,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp =  5,
		.h_bp = 40,
		.h_sw =  2,
		.v_fp =  8,
		.v_fpe = 1,
		.v_bp =  8,
		.v_bpe = 1,
		.v_sw =  2,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};
#endif

static struct s3cfb_lcd wvga_a97 = {
	.width = 1024,
	.height = 768,
	.p_width = 200,
	.p_height = 150,
	.bpp = 32,
	.freq = 62,

	.timing = {
		.h_fp = 12,
		.h_bp = 12,
		.h_sw = 4,
		.v_fp = 8,
		.v_fpe = 1,
		.v_bp = 8,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

/* VGAs */
static struct s3cfb_lcd wvga_l80 = {
	.width= 640,
	.height = 480,
	.p_width = 160,
	.p_height = 120,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 35,
		.h_bp = 53,
		.h_sw = 73,
		.v_fp = 3,
		.v_fpe = 1,
		.v_bp = 29,
		.v_bpe = 1,
		.v_sw = 6,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};


static struct s3cfb_lcd wvga_g10 = {
	.width= 640,
	.height = 480,
	.p_width = 213,
	.p_height = 160,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 0x3c,
		.h_bp = 0x63,
		.h_sw = 1,
		.v_fp = 0x0a,
		.v_fpe = 1,
		.v_bp = 0x22,
		.v_bpe = 1,
		.v_sw = 1,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 0,
		.inv_vsync = 0,
		.inv_vden = 0,
	},
};


static struct s3cfb_lcd wvga_a56 = {
	.width= 640,
	.height = 480,
	.p_width = 112,
	.p_height = 84,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 16,
		.h_bp = 134,
		.h_sw = 10,
		.v_fp = 32,
		.v_fpe = 1,
		.v_bp = 11,
		.v_bpe = 1,
		.v_sw = 2,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#if YTS280DLAT_01_102C
static struct s3cfb_lcd wvga_w35 = {
	.width= 240,
	.height = 320,
	.p_width = 70,
	.p_height = 52,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp =  50,
		.h_bp = 50,
		.h_sw =  50,
		.v_fp =  50,
		.v_fpe = 1,
		.v_bp = 50,
		.v_bpe = 1,
		.v_sw = 50,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

#elif YTC350HLAB_01_100C
static struct s3cfb_lcd wvga_w35 = {
	.width = 320,
	.height = 480,
	.p_width = 96,
	.p_height = 54,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp =  38,
		.h_bp = 50,
		.h_sw =  50,
		.v_fp =  35,
		.v_fpe = 1,
		.v_bp =  19,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 1,
	},
};

#elif YTS350ELAK 
static struct s3cfb_lcd wvga_w35 = {
	.width= 320,
	.height = 240,
	.p_width = 70,
	.p_height = 52,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp =  20,
		.h_bp = 68,
		.h_sw =  68,
		.v_fp =  4,
		.v_fpe = 1,
		.v_bp = 18,
		.v_bpe = 1,
		.v_sw =  18,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 0,
		.inv_vsync = 0,
		.inv_vden = 1,
	},
};
#elif YTS350ELAK_01_200C 
static struct s3cfb_lcd wvga_w35 = {
	.width= 320,
	.height = 240,
	.p_width = 70,
	.p_height = 52,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp =  20,
		.h_bp = 68,
		.h_sw =  68,
		.v_fp =  4,
		.v_fpe = 1,
		.v_bp = 18,
		.v_bpe = 1,
		.v_sw =  18,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 0,
		.inv_vsync = 0,
		.inv_vden = 1,
	},
};

#else
static struct s3cfb_lcd wvga_w35 = {
	.width= 320,
	.height = 240,
	.p_width = 70,
	.p_height = 52,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp =  4,
		.h_bp = 70,
		.h_sw =  4,
		.v_fp =  4,
		.v_fpe = 1,
		.v_bp = 12,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 0,
		.inv_vsync = 0,
		.inv_vden = 0,
	},
};
#endif

/* HDMI */
static struct s3cfb_lcd hdmi_def = {
	.width = 1920,
	.height = 1080,
	.p_width = 480,
	.p_height = 320,
	.bpp = 32,
	.freq = 62,

	.timing = {
		.h_fp = 12,
		.h_bp = 12,
		.h_sw = 4,
		.v_fp = 8,
		.v_fpe = 1,
		.v_bp = 8,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct hdmi_config {
	char *name;
	int width;
	int height;
} mini210_hdmi_config[] = {
	{ "HDMI1080P60",	1920, 1080 },
	{ "HDMI1080I60",	1920, 1080 },
	{ "HDMI1080P30",	1920, 1080 },

	{ "HDMI1080P60D",	 960,  536 },
	{ "HDMI1080I60D",	 960,  536 },
	{ "HDMI1080P30D",	 960,  536 },

	{ "HDMI720P60",		1280,  720 },
	{ "HDMI720P60D",	 640,  360 },

	{ "HDMI576P16X9",	 720,  576 },
	{ "HDMI576P16X9D",	 720,  576 },
	{ "HDMI576P4X3",	 720,  576 },
	{ "HDMI576P4X3D",	 720,  576 },

	{ "HDMI480P16X9",	 720,  480 },
	{ "HDMI480P16X9D",	 720,  480 },
	{ "HDMI480P4X3",	 720,  480 },
	{ "HDMI480P4X3D",	 720,  480 },
};


/* Try to guess LCD panel by kernel command line, or
 * using *W50* as default */

static struct {
	char *name;
	struct s3cfb_lcd *lcd;
	int ctp;
} mini210_lcd_config[] = {
	{ "W50",  &wvga_w50,  1 },
	{ "A70",  &wvga_a70,  1 },
	{ "S70",  &wvga_s70,  1 },
	{ "H43",  &wvga_h43,  1 },
	{ "A97",  &wvga_a97,  1 },
	{ "L80",  &wvga_l80,  1 },
	{ "G10",  &wvga_g10,  1 },
	{ "A56",  &wvga_a56,  1 },
	{ "W101", &wvga_w101, 1 },
	{ "W35",  &wvga_w35,  1 },
	{ "HDM",  &hdmi_def,  1 },	/* Pls keep it at last */
};

static int lcd_idx = 2;

static int __init mini210_setup_lcd(char *str)
{
	int i;

	if (!strncasecmp("HDMI", str, 4)) {
		struct hdmi_config *cfg = &mini210_hdmi_config[0];
		struct s3cfb_lcd *lcd;

		lcd_idx = ARRAY_SIZE(mini210_lcd_config) - 1;
		lcd = mini210_lcd_config[lcd_idx].lcd;
		lcd->args = lcd_idx;

		for (i = 0; i < ARRAY_SIZE(mini210_hdmi_config); i++, cfg++) {
			if (!strcasecmp(cfg->name, str)) {
				lcd->width = cfg->width;
				lcd->height = cfg->height;
				goto __ret;
			}
		}
	}

	for (i = 0; i < ARRAY_SIZE(mini210_lcd_config); i++) {
		if (!strcasecmp(mini210_lcd_config[i].name, str)) {
			lcd_idx = i;
			mini210_lcd_config[lcd_idx].lcd->args = lcd_idx;
			break;
		}
	}

__ret:
	printk("MINI210: %s selected\n", mini210_lcd_config[lcd_idx].name);
	return 0;
}
early_param("lcd", mini210_setup_lcd);


struct s3cfb_lcd *mini210_get_lcd(void)
{
	return mini210_lcd_config[lcd_idx].lcd;
}

void mini210_get_lcd_res(int *w, int *h)
{
	struct s3cfb_lcd *lcd = mini210_lcd_config[lcd_idx].lcd;

	if (w)
		*w = lcd->width;
	if (h)
		*h = lcd->height;

	return;
}
EXPORT_SYMBOL(mini210_get_lcd_res);


#if defined(CONFIG_TOUCHSCREEN_GOODIX) || \
	defined(CONFIG_TOUCHSCREEN_FT5X0X)
static unsigned int ctp_type = CTP_NONE;

static int __init mini210_set_ctp(char *str)
{
	unsigned int val;
	char *p = str, *end;

	val = simple_strtoul(p, &end, 10);
	if (end <= p) {
		return 1;
	}

	if (val < CTP_MAX && mini210_lcd_config[lcd_idx].ctp) {
		ctp_type = val;
	}

	return 1;
}
__setup("ctp=", mini210_set_ctp);

unsigned int mini210_get_ctp(void)
{
	return ctp_type;
}
EXPORT_SYMBOL(mini210_get_ctp);
#endif

