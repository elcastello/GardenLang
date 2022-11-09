void term_init() {
	term_row = 0;
	term_col = 0;
	int y;
	int x;

	term_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	for (y = 0; y < VGA_HEIGHT; y++) {
		for (x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			term_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}