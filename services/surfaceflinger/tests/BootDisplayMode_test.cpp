/*
 * Copyright 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thread>

#include <gtest/gtest.h>

#include <gui/SurfaceComposerClient.h>
#include <private/gui/ComposerService.h>
#include <chrono>

namespace android {

TEST(BootDisplayModeTest, setBootDisplayMode) {
    sp<ISurfaceComposer> sf(ComposerService::getComposerService());
    auto displayToken = SurfaceComposerClient::getInternalDisplayToken();
    bool bootModeSupport = false;
    ASSERT_NO_FATAL_FAILURE(sf->getBootDisplayModeSupport(&bootModeSupport));
    if (bootModeSupport) {
        ASSERT_EQ(NO_ERROR, sf->setBootDisplayMode(displayToken, 0));
    }
}

TEST(BootDisplayModeTest, clearBootDisplayMode) {
    sp<ISurfaceComposer> sf(ComposerService::getComposerService());
    auto displayToken = SurfaceComposerClient::getInternalDisplayToken();
    bool bootModeSupport = false;
    ASSERT_NO_FATAL_FAILURE(sf->getBootDisplayModeSupport(&bootModeSupport));
    if (bootModeSupport) {
        ASSERT_EQ(NO_ERROR, sf->clearBootDisplayMode(displayToken));
    }
}

} // namespace android