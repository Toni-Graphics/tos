#include <drivers/GraphicsDriver.hpp>
#include <panic.hpp>
#include <stddef.h>

#ifdef DEBUG
#include <Logger.hpp>
#endif

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

graphicsDriver::graphicsDriver() {}

void graphicsDriver::putPixel(int x, int y, long color) {
    uint32_t *fb_ptr = reinterpret_cast<uint32_t*>(this->framebuf.address);
    fb_ptr[y * (this->getPitch() / 4) + x] = color;
}

void graphicsDriver::init() {
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        panic("could not get framebuffer response");
    }

    // Fetch the first framebuffer.
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    this->framebuf = *framebuffer;
#ifdef DEBUG
    Logger.sucess("inited graphics driver");
#endif

}

uint64_t graphicsDriver::getPitch() {
    return this->framebuf.pitch;
}

uint64_t graphicsDriver::getHeight() {
    return this->framebuf.height;
}

uint64_t graphicsDriver::getWidth() {
    return this->framebuf.width;
}

uint16_t graphicsDriver::getBpp() {
    return this->framebuf.bpp;
}

uint8_t graphicsDriver::getMemory_model() {
    return this->framebuf.memory_model;
}

uint8_t graphicsDriver::getRed_mask_size() {
    return this->framebuf.red_mask_size;
}

uint8_t graphicsDriver::getRed_mask_shift() {
    return this->framebuf.red_mask_shift;
}

uint8_t graphicsDriver::getGreen_mask_size() {
    return this->framebuf.green_mask_size;
}

uint8_t graphicsDriver::getGreen_mask_shift() {
    return this->framebuf.green_mask_shift;
}

uint8_t graphicsDriver::getBlue_mask_size() {
    return this->framebuf.blue_mask_size;
}

uint8_t graphicsDriver::getBlue_mask_shift() {
    return this->framebuf.blue_mask_shift;
}


extern graphicsDriver GraphicsDriver = graphicsDriver();