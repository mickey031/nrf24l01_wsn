/*
 * pic24f RTOS based OS
 * Copyright (C) 2015 <spiriou31@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PIC24F_SPI2_H
#define PIC24F_SPI2_H

#include <stdint.h>
#include "spi.h"

extern struct spi_driver pic24f_spi2_driver;

// Export this structure to allocate on stack
struct pic24f_spi_info {
    // Transfer queue
    struct spi_msg *head;
    struct spi_msg *tail;
    // Current request
    struct spi_req *req;
    // Index on request buffers
    unsigned int tx_index;
    unsigned int rx_index;
    // Master device configuration
    uint16_t *spi_con1;
    uint16_t *spi_con2;
    uint16_t *spi_stat;
    // TODO: add other registers
};

#endif
