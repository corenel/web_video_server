#ifndef H264_NVENC_STREAMERS_H_
#define H264_NVENC_STREAMERS_H_

#include <image_transport/image_transport.h>
#include "async_web_server_cpp/http_connection.hpp"
#include "async_web_server_cpp/http_request.hpp"
#include "web_video_server/libav_streamer.h"

namespace web_video_server {

class H264NVENCStreamer : public LibavStreamer {
 public:
  H264NVENCStreamer(const async_web_server_cpp::HttpRequest& request,
                    async_web_server_cpp::HttpConnectionPtr connection,
                    ros::NodeHandle& nh);
  ~H264NVENCStreamer();

 protected:
  virtual void initializeEncoder();
  std::string preset_;
};

class H264NVENCStreamerType : public LibavStreamerType {
 public:
  H264NVENCStreamerType();
  virtual boost::shared_ptr<ImageStreamer> create_streamer(
      const async_web_server_cpp::HttpRequest& request,
      async_web_server_cpp::HttpConnectionPtr connection, ros::NodeHandle& nh);
};

}  // namespace web_video_server

#endif
