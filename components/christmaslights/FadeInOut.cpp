#include "FadeInOut.h"
#include "Fade.h"

const float fade_step = 0.001;

void FadeInOut::init() {
    fadeIn_ = new Fade(strand1_, strand2_, 5, fade_step);
    fadeOut_ = new Fade(strand2_, strand1_, 5, fade_step);
    in_ = true;
    lastStep_ = 0;
    current_ = 0;
}

void FadeInOut::tick() {
    if (in_) {
        fadeIn_->loop();
    } else {
        fadeOut_->loop();
    }
    current_ += fade_step;

    if (current_ >= 1) {
        in_ = !in_;
        current_ = 0;
        fadeIn_->init();
        fadeOut_->init();
    }
}