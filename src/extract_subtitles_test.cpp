//
// Created by gregw on 4/27/2023.
//
#include <iostream>
#include <vector>

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

int main() {
    // Open the video file.
    AVFormatContext *format_context = avformat_alloc_context();
    if (avformat_open_input(&format_context, "video.mp4", NULL, NULL) != 0) {
        std::cerr << "Could not open video file." << std::endl;
        return 1;
    }

    // Get the number of subtitle streams.
    int num_subtitle_streams = format_context->nb_streams;

    // Iterate over the subtitle streams.
    for (int i = 0; i < num_subtitle_streams; i++) {
        if (format_context->streams[i]->codec->codec_type == AVMEDIA_TYPE_SUBTITLE) {
            // Get the subtitle codec context.
            AVCodecContext *codec_context = format_context->streams[i]->codec;

            // Create a subtitle buffer.
            AVSubtitle *subtitle = avsubtitle_alloc();

            // Read a subtitle from the video file.
            int ret = avcodec_decode_subtitle2(codec_context, subtitle, NULL, 0);
            if (ret < 0) {
                std::cerr << "Could not decode subtitle." << std::endl;
                return 1;
            }

            // Add the subtitle to the array.
            std::vector<AVSubtitle> subtitles;
            subtitles.push_back(*subtitle);

            // Free the subtitle buffer.
            avsubtitle_free(&subtitle);
        }
    }

    // Close the video file.
    avformat_close_input(&format_context);

    // Print the subtitles.
    for (int i = 0; i < subtitles.size(); i++) {
        std::cout << "Subtitle " << i << ": " << subtitles[i].start_time << " - " << subtitles[i].end_time << " - " << subtitles[i].text << std::endl;
    }

    return 0;
}
