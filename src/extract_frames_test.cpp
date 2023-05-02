//
// Created by gregw on 4/27/2023.
//

#include "extract_frames_test.h"

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

    // Get the number of video streams.
    int num_streams = format_context->nb_streams;

    // Iterate over the video streams.
    for (int i = 0; i < num_streams; i++) {
        if (format_context->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            // Get the video codec context.
            AVCodecContext *codec_context = format_context->streams[i]->codec;

            // Create a frame buffer.
            AVFrame *frame = av_frame_alloc();

            // Read a frame from the video file.
            int ret = avcodec_decode_video2(codec_context, frame, NULL, 0);
            avcodec_find_decoder(codec_context)
            if (ret < 0) {
                std::cerr << "Could not decode video frame." << std::endl;
                return 1;
            }

            // Save the frame to a file.
            char filename[1024];
            sprintf(filename, "frame-%04d.jpg", i);
            if (av_image_write_to_file(frame->data, frame->linesize, codec_context->pix_fmt, filename, 100) != 0) {
                std::cerr << "Could not write frame to file." << std::endl;
                return 1;
            }

            // Free the frame buffer.
            av_frame_free(&frame);
        }
    }

    // Close the video file.
    avformat_close_input(&format_context);

    return 0;
}