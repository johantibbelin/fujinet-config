#ifdef BUILD_ATARI16BIT
#ifdef ACSI_H
#define ACSI_H
#include <stdint.h>


struct acsi_cmd_frame
{
    uint8_t id_cmd;
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
    uint8_t byte4;
    uint8_t control_byte;
};

/**
 * ACSI functions
*/

uint8_t acsi_cmd_test_unit_ready();
/**
 * Write blocks (sectors)
 * @param id ACSI id
 * @param start_block Start at block
 * @param nblocks Number of blocks (sectors (512byte)) 
*/
uint8_t acsi_cmd_write_blocks(uint8_t id,uint32_t start_block, uint8_t nblocks);

/**
 * Read blocks (sectors)
 * @param id ACSI id
 * @param start_block Start at block
 * @param nblocks Number of blocks (sectors (512byte)) 
*/
uint8_t acsi_read_blocks(uint8_t id,uint32_t start_block, uint8_t nblocks);

/**
 * Send SIO commad (cmd nr 0x01)
 * 
*/
uint8_t acsi_cmd_send_sio(uint8_t id,uint8_t sio_id, uint8_t sio_cmd, uint8_t sio_aux1, uint8_t sio_aux2, uint8_t sio_chksum);

/**
 * Assembler functions
*/
uint8_t acsi_send_command(acsi_cmd_frame *acsi_cmd);
#endif /* ACSI_H */
#endif /* BUILD_ATARI16BIT */