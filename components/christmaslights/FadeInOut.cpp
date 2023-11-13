#include "FadeInOut.h"
#include "Fade.h"
// #include "esphome/core/log.h"

const float fade_step = 0.001;
// static const char *const TAG = "christmasLigths";

#define esp_log_printf_ esphome::esp_log_printf_

FadeInOut::FadeInOut(
    esphome::output::FloatOutput *strand1,
    esphome::output::FloatOutput *strand2,
    int waitFactor
): ModeInterface(strand1, strand2, waitFactor) {
    fadeIn_ = new Fade(strand1_, strand2_, 5, fade_step);
    fadeOut_ = new Fade(strand2_, strand1_, 5, fade_step);
    in_ = true;
    lastStep_ = 0;
    current_ = 0;
}

void FadeInOut::init() {
}

void FadeInOut::tick() {
    if (in_) {
        fadeIn_->loop();
    } else {
        fadeOut_->loop();
    }
    current_ += fade_step;

    if (current_ > 1) {
        in_ = !in_;
        current_ = 0;
        if (in_) {
            // ESP_LOGI(TAG, "Flipping direction in");
            fadeIn_->init();
        } else {
            // ESP_LOGI(TAG, "Flipping direction out");
            fadeOut_->init();
        }
    }
}