#include "web_video_server/h264_nvenc_streamer.h"

namespace web_video_server {

H264NVENCStreamer::H264NVENCStreamer(
    const async_web_server_cpp::HttpRequest& request,
    async_web_server_cpp::HttpConnectionPtr connection, ros::NodeHandle& nh)
    : LibavStreamer(request, connection, nh, "mp4", "h264_nvenc", "video/mp4") {
  /* possible quality presets:
   * ultrafast, superfast, veryfast, faster, fast, medium, slow, slower,
   * veryslow, placebo no latency improvements observed with ultrafast instead
   * of medium
   */
  preset_ = request.get_query_param_value_or_default("preset", "ll");
}

H264NVENCStreamer::~H264NVENCStreamer() {}

void H264NVENCStreamer::initializeEncoder() {
  av_opt_set(codec_context_->priv_data, "preset", preset_.c_str(), 0);
  //  av_opt_set_int(codec_context_->priv_data, "crf", 1, 0);
  av_opt_set_int(codec_context_->priv_data, "zerolatency", 1, 0);

  //  av_opt_set(codec_context_->priv_data, "tune", "zerolatency", 0);
  //  av_opt_set_int(codec_context_->priv_data, "bufsize", 100, 0);
  //  av_opt_set_int(codec_context_->priv_data, "keyint", 30, 0);
  //  av_opt_set_int(codec_context_->priv_data, "g", 1, 0);

  // container format options
  if (!strcmp(format_context_->oformat->name, "mp4")) {
    // set up mp4 for streaming (instead of seekable file output)
    av_dict_set(&opt_, "movflags", "+frag_keyframe+empty_moov+faststart", 0);
  }
}

H264NVENCStreamerType::H264NVENCStreamerType()
    : LibavStreamerType("mp4", "h264_nvenc", "video/mp4") {}

boost::shared_ptr<ImageStreamer> H264NVENCStreamerType::create_streamer(
    const async_web_server_cpp::HttpRequest& request,
    async_web_server_cpp::HttpConnectionPtr connection, ros::NodeHandle& nh) {
  return boost::shared_ptr<ImageStreamer>(
      new H264NVENCStreamer(request, connection, nh));
}

}  // namespace web_video_server
