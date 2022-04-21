#pragma once

namespace Images {

  const uint8_t PROGMEM PPOT[] = {
#ifndef DEBUG
    65, 32, // 65x31 px image
    /*
    ⡎⠍⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⡇⢸⣏⣹⠆⣿⣉⡷⢸⣏⡉⠁⢾⣉⡓⠰⣏⣙⠂
    ⡇⢸⣿⢩⣫⢹⠭⠭⠭⠭⠭⠭⠭⠀⡇⠸⠇⠀⠀⠿⠙⠦⠸⠧⠤⠄⠲⠤⠟⠐⠦⠼⠃
    ⡇⢸⣿⣾⣾⢊⡭⢭⡉⠉⠉⣉⠉⠀⡇⢸⣏⣹⠆⣿⠀⠀⢠⣞⣳⡄⢿⣀⡿⢸⣷⣄⠀
    ⡇⢸⣿⣿⣿⠸⣌⣢⠇⠉⠁⣿⠀⠀⡇⠸⠇⠀⠀⠿⠤⠤⠸⠇⠸⠇⠀⠿⠀⠸⠟⠁⠀
    ⡇⢸⣿⠛⠛⢳⠶⡶⡶⡶⢶⠶⡶⠀⡇⢰⡏⢹⡆⣿⣦⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⡇⠈⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠀⡇⠘⠧⠼⠃⠿⠈⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⡇⠀⠀⡰⠉⣉⠉⠉⣉⠉⠉⠉⠉⠀⡇⠈⢹⡏⠁⣴⣛⣦⢸⣏⣹⠆⣿⣉⠉⠀⠀⠀⠀
    ⠣⠥⠤⠧⠤⠭⠤⠤⠭⠤⠤⠤⠤⠀⠇⠀⠸⠇⠀⠿⠀⠿⠸⠇⠀⠀⠿⠤⠤⠀⠀⠀⠀
    */
    0xfe, 0x01, 0x05, 0xf1, 0xf1, 0xf1, 0x11, 0xd1, 0xb1, 0xd1, 0x11, 0xf1, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x51, 0x00, 0x00, 0xff, 0x00, 0x00, 0x7f, 0x7f, 0x09, 0x09, 0x0f, 0x06, 0x00, 0x7f, 0x7f, 0x19, 0x39, 0x6f, 0x46, 0x00, 0x7f, 0x7f, 0x49, 0x49, 0x41, 0x41, 0x00, 0x26, 0x6f, 0x49, 0x49, 0x7b, 0x32, 0x00, 0x26, 0x6f, 0x49, 0x49, 0x7b, 0x32, 
    0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0x02, 0x79, 0xcd, 0x95, 0xa5, 0xcd, 0x79, 0x01, 0x11, 0x11, 0x11, 0x01, 0xf9, 0xf9, 0x01, 0x01, 0x00, 0x00, 0xff, 0x00, 0x00, 0x7f, 0x7f, 0x09, 0x09, 0x0f, 0x06, 0x00, 0x7f, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x00, 0x7c, 0x7e, 0x0b, 0x0b, 0x7e, 0x7c, 0x00, 0x07, 0x0f, 0x78, 0x78, 0x0f, 0x07, 0x00, 0x7F, 0x7F, 0x3E, 0x1C, 0x08, 0x00,
    0xff, 0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3e, 0x36, 0x36, 0x3e, 0x36, 0x3e, 0x36, 0x3e, 0x36, 0x36, 0x3e, 0x36, 0x36, 0x3e, 0x36, 0x00, 0x00, 0xff, 0x00, 0x00, 0x3e, 0x7f, 0x41, 0x41, 0x7f, 0x3e, 0x00, 0x7f, 0x7f, 0x0e, 0x1c, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x3f, 0x40, 0x50, 0x40, 0x40, 0x40, 0x78, 0x46, 0x41, 0x41, 0x59, 0x59, 0x41, 0x41, 0x41, 0x41, 0x59, 0x59, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x01, 0x01, 0x7f, 0x7f, 0x01, 0x01, 0x00, 0x7c, 0x7e, 0x0b, 0x0b, 0x7e, 0x7c, 0x00, 0x7f, 0x7f, 0x09, 0x09, 0x0f, 0x06, 0x00, 0x7f, 0x7f, 0x49, 0x49, 0x41, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
#else
    1,1,1
#endif
  };

  //  const uint8_t PROGMEM PPOT_Pixel[] = {
  //      1, 8,  // 1x8 px images
  //      0x11,  // ▓▓▓░▓▓▓░ Frame 0
  //      0x31,  // ▓▓░░▓▓▓░ Frame 1
  //      0x51,  // ▓░▓░▓▓▓░ Frame 2
  //      0x91   // ░▓▓░▓▓▓░ Frame 3
  //  };
  //
  //  const uint8_t PROGMEM PPOT_Spindle[] = {
  //      2, 8,  // 2x8 px image
  //      0xA5,  // ░▓░▓▓░▓░
  //      0x95   // ░▓▓░▓░▓░
  //  };


  const uint8_t PROGMEM Farkle[] ={
  104, 48,
  0x00, 0xe0, 0x10, 0x10, 0x88, 0x48, 0x88, 0x48, 0x88, 0x48, 0x88, 0xc4, 0xa4, 0xc4, 0xa4, 0xc4, 
  0xa4, 0xc4, 0xa4, 0xd2, 0xe2, 0xd2, 0xe2, 0xd2, 0xe2, 0xd2, 0xe2, 0x02, 0x0c, 0xf0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
  0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x04, 0xa4, 0x44, 0xa4, 0xc4, 0xe4, 
  0x04, 0x08, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x0a, 0x55, 0xaf, 0xff, 
  0xff, 0xff, 0xff, 0xe3, 0x03, 0x03, 0x39, 0x29, 0x29, 0x29, 0x29, 0x29, 0xa9, 0x95, 0x94, 0x94, 
  0x94, 0x24, 0x24, 0x22, 0x92, 0x11, 0x90, 0x90, 0x90, 0x90, 0x90, 0xa0, 0x20, 0x20, 0x20, 0x40, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0xff, 0x00, 
  0x00, 0xaa, 0x55, 0xfe, 0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
  0xfe, 0x00, 0x00, 0xaa, 0x55, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xfc, 0x80, 0x40, 0x20, 0x10, 
  0x10, 0x90, 0x10, 0x90, 0x90, 0x90, 0x90, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x2a, 0x55, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x9f, 
  0x9f, 0x9f, 0x4f, 0x4f, 0xcf, 0x0f, 0x0f, 0x4f, 0xa7, 0xd0, 0xfa, 0xfd, 0x3e, 0x0f, 0x07, 0x63, 
  0x53, 0x49, 0x71, 0x03, 0x07, 0x57, 0xfe, 0xfe, 0xfc, 0x00, 0xa8, 0x54, 0xf8, 0xf4, 0xf8, 0x00, 
  0xc3, 0xf0, 0xf8, 0x74, 0xf8, 0xf4, 0xf8, 0xf0, 0xe0, 0x0a, 0x55, 0xff, 0xff, 0xff, 0x00, 0x00, 
  0x7f, 0x20, 0x10, 0x08, 0x88, 0x44, 0xa4, 0xd2, 0xe3, 0x70, 0x30, 0x12, 0xa5, 0x7f, 0xff, 0xff, 
  0xff, 0xf8, 0x00, 0x83, 0x51, 0xa8, 0xf4, 0xfa, 0x3d, 0x0e, 0x07, 0x23, 0x33, 0x33, 0x03, 0x87, 
  0x5f, 0xbe, 0xfc, 0xf8, 0x01, 0x06, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x01, 
  0xaa, 0x57, 0xff, 0xff, 0xff, 0xfe, 0x80, 0x00, 0x7f, 0x80, 0x00, 0xe0, 0x18, 0x05, 0xa2, 0x50, 
  0xe8, 0xf4, 0xfc, 0x7e, 0x3e, 0x1e, 0x8e, 0xce, 0xe6, 0x26, 0x06, 0x86, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0x00, 0x0a, 0x55, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0xf8, 0x10, 0x13, 0xf3, 0x03, 
  0x03, 0xa8, 0x55, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf8, 0xf4, 0xfa, 0xed, 0xce, 0x07, 0x33, 0x51, 
  0x88, 0x04, 0xf8, 0x00, 0x02, 0x55, 0xab, 0xff, 0xff, 0xff, 0x00, 0xfa, 0xfd, 0xff, 0xff, 0x0f, 
  0x07, 0x67, 0x67, 0x66, 0x27, 0x06, 0x87, 0x46, 0xa7, 0xc7, 0x47, 0x03, 0x10, 0xe8, 0x07, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x15, 0x2a, 0x7f, 0x3f, 0x3f, 0x3f, 0x20, 
  0x00, 0x8f, 0x70, 0x01, 0x06, 0x08, 0x10, 0x25, 0x4f, 0x4f, 0x4f, 0x9e, 0x9c, 0x9d, 0x9d, 0x9c, 
  0x9c, 0x4e, 0x4d, 0x8e, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x80, 0x00, 0x05, 0xab, 0x5f, 0xff, 0x7f, 
  0x7f, 0x78, 0x00, 0x07, 0xf8, 0x00, 0xff, 0x00, 0x00, 0x2a, 0x55, 0x7f, 0x7f, 0x7f, 0x01, 0x00, 
  0xf8, 0x11, 0x23, 0x47, 0x8e, 0x3d, 0x3a, 0x74, 0x28, 0x51, 0x23, 0x40, 0x00, 0x05, 0xea, 0x27, 
  0x2f, 0x2f, 0x2f, 0x10, 0x09, 0x13, 0x17, 0x17, 0x16, 0x24, 0x2e, 0x2c, 0x2e, 0x25, 0x26, 0x13, 
  0x11, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x01, 
  0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 
  0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };

  const uint8_t PROGMEM Farkle_Mask[] ={
  0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 
  0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 
  0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 
  0xfe, 0xfe, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 
  0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf0, 0xf8, 0xf8, 
  0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 
  0x00, 0x01, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 
  0x00, 0x00, 0x00, 0x00, 0x01, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
  0x3f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 
  0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x03, 0x07, 
  0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 
  0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };

  const uint8_t PROGMEM Title_Dice[] ={
  96, 32,
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0xa0, 0xa0, 0x90, 0xd0, 0xc8, 0xe8, 0xe4, 0xf4, 
  0xf2, 0x1a, 0x02, 0xc4, 0x68, 0xd0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 
  0xf0, 0xc3, 0x0f, 0x3f, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x3e, 0x3e, 0x3c, 0x7c, 0xfd, 0xfd, 
  0xfd, 0xf2, 0xcc, 0x10, 0x60, 0x80, 0x00, 0x80, 0x80, 0x40, 0x40, 0x20, 0xa0, 0x90, 0xd0, 0xc8, 
  0xe8, 0xe4, 0x34, 0x04, 0x88, 0xd0, 0xa0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
  0x78, 0x86, 0xf9, 0xfd, 0xfe, 0xfe, 0xff, 0x9f, 0x8f, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x07, 0x00, 0xf0, 0xff, 0xfc, 0xf8, 0xff, 0xe2, 0xc5, 0x6a, 0x14, 0xc8, 0xe6, 0x91, 0x0c, 0x88, 
  0xff, 0xff, 0xff, 0xfc, 0xf0, 0x43, 0x0f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3e, 0x3e, 0x3f, 0x7f, 
  0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x79, 0x67, 0x0a, 0x76, 0x0f, 0x9f, 0x7f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0x0f, 0x00, 0xe0, 0xff, 0xf1, 0xf3, 0xfe, 0x8d, 0x9a, 0xf4, 0x28, 0x10, 0xcc, 0x32, 0x19, 
  0x30, 0xc0, 0x06, 0x1e, 0x7e, 0xfc, 0xfc, 0xfc, 0xfc, 0xfd, 0xfd, 0x7d, 0x7d, 0x79, 0xf9, 0xfb, 
  0xfa, 0xfb, 0xe6, 0x9d, 0x2a, 0xd5, 0x2b, 0x97, 0x9f, 0x9f, 0xcf, 0xcf, 0xcf, 0xe7, 0xe7, 0xc1, 
  0x80, 0x1e, 0x30, 0x70, 0xff, 0x8f, 0x07, 0x31, 0xf8, 0xfe, 0xff, 0xff, 0x9f, 0x0f, 0x0f, 0x9f, 
  0x3f, 0x1f, 0x0f, 0x23, 0x31, 0x38, 0x1e, 0x17, 0x13, 0x31, 0x31, 0x3b, 0x3f, 0x3f, 0x3e, 0x3e, 
  0x3e, 0x26, 0x22, 0x02, 0x26, 0x14, 0x2a, 0x14, 0x2a, 0x35, 0x3e, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 
  0x03, 0x00, 0x3c, 0x23, 0x31, 0x3f, 0x1f, 0x0f, 0x23, 0x31, 0x3c, 0x3e, 0x3f, 0x3f, 0x1e, 0x1c, 
  0x3e, 0x3f, 0x3f, 0x3e, 0x38, 0x21, 0x07, 0x1f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3c, 0x3c, 0x3c, 0x3f, 
  0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3c, 0x31, 0x0a, 0x15, 0x2f, 0x3f, 0x2f, 0x0f, 0x0f, 0x0f, 0x1f, 
  0x3f, 0x3f, 0x3e, 0x3c, 0x38, 0x31, 0x23, 0x06, 0x08, 0x03, 0x0f, 0x3f, 0x1f, 0x1f, 0x3f, 0x3f, 
  };

  const uint8_t PROGMEM Title_Dice_Mask[] ={
  0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 
  0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 
  0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 
  0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xfc, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
  0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
  0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
  0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
  0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
  0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
  };

};