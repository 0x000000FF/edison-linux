/* board support file example */

#include <linux/input.h>
#include <linux/rotary_encoder.h>
#include <linux/platform_device.h>

#define GPIO_ROTARY_A 80
#define GPIO_ROTARY_B 81

static struct rotary_encoder_platform_data my_rotary_encoder_info = {
	.steps			= 24,
	.axis			= EV_REL,
	.relative_axis	= true,
	.rollover		= true,
	.gpio_a			= GPIO_ROTARY_A,
	.gpio_b			= GPIO_ROTARY_B, 
	.inverted_a		= 0,
	.inverted_b		= 0,
	.half_period	= false,
};

static struct platform_device rotary_encoder_device = {
	.name	= "rotary-encoder",
	.id		= 0,
	.dev	= {
		.platform_data = &my_rotary_encoder_info,
	}
};

static int __init rotary_encoder_init(void)
{
	pr_info("init rotary encoder");
	return platform_device_register(&rotary_encoder_device);
}

late_initcall(rotary_encoder_init);