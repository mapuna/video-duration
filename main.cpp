/**
 * Copytight 2024 Anupam Gupta
 */

#include <iostream>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

double duration_seconds(const char *file_path) {
  AVFormatContext *pFormatCtx = nullptr;

  if (avformat_open_input(&pFormatCtx, file_path, NULL, NULL) < 0) {
    std::cerr << "Error opening video file." << std::endl;
    return -1;
  }

  if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
    std::cerr << "Error finding stream information." << std::endl;
    avformat_close_input(&pFormatCtx);
    return -1;
  }

  // Check if the file has a valid duration
  if (pFormatCtx->duration != AV_NOPTS_VALUE) {
    int64_t duration = pFormatCtx->duration;
    double durationInSeconds = (double)duration / AV_TIME_BASE;
    return durationInSeconds;
  } else {
    std::cerr << "Invalid video duration." << std::endl;
    return -1;
  }
  // Close the file and release resources
  avformat_close_input(&pFormatCtx);
}

int main() {
  const char *file_path =
      "D:\\Videos\\Local\\Movies\\Austin "
      "Powers\\Austin.Powes.in.Goldmember.2002.1080p.BluRay.x265-.mp4";
  double durationInSeconds = duration_seconds(file_path);
  std::cout << "Video duration: " << durationInSeconds << " seconds"
            << std::endl;

  return 0;
}
