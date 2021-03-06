// Copyright (c) 2017 Leosocy. All rights reserved.
// Use of this source code is governed by a MIT-style license 
// that can be found in the LICENSE file.

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>
#include <set>
#include "util/pub.h"

namespace edcc
{

namespace config
{

static const char* const kImageWidth = "imageSizeW";
static const char* const kImageHeight = "imageSizeH";
static const char* const kGaborKernelSize = "gaborKernelSize";
static const char* const kLaplaceKernelSize = "laplaceKernelSize";
static const char* const kGaborDirections = "gaborDirections";
static const char* const kCodingMode = "codingMode";
static const char* const kMatchingMode = "matchingMode";

} // namespace config

namespace limit
{

static const u_short kMinImageWidth = 29;
static const u_short kMinImageHeight = 29;
static const u_char kMaxLaplaceKernelSize = 31;
static const u_char kMinGaborDirections = 4;
static const u_char kMaxGabotDirections = 16;
#define COMPRESSION_CODING_MODE 1
#define FAST_CODING_MODE        2
static const u_char kSupportedCodingModes[] =
{
    COMPRESSION_CODING_MODE,
    FAST_CODING_MODE
};
#define RELIABLE_MATCHING_MODE  1
#define SPEED_MATCHING_MODE     2
static const u_char kSupportedMatchingModes[] =
{
    RELIABLE_MATCHING_MODE,
    SPEED_MATCHING_MODE
};

}; // namespace limit

typedef struct tag_EDCC_CFG_T
{
    u_short imageSizeW;
    u_short imageSizeH;
    u_short gaborSize;
    u_char laplaceSize;
    u_char directions;
    u_char codingMode;
    u_char matchingMode;
} EDCC_CFG_T;

class ConfigManager
{
public:
    ConfigManager();
    bool GetConfigValue(const std::string &key, int *value);
    bool SetConfigValue(const std::string &key, int value);
    bool IsKeyInConfigParams(const std::string &key)
    { 
        return params_.find(key) != params_.end();
    }
    const EDCC_CFG_T& config() const { return cfg_; }
    const std::set<std::string>& params() const { return params_; }
private:
    EDCC_CFG_T cfg_;
    std::set<std::string> params_;
};

} // namespace edcc

#endif // !__CONFIG_H__
