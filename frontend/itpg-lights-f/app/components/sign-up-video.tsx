import React from "react";

const Video = () => {
  return (
    <div>
      <video width="320" height="240" controls preload="none">
        <source src="/path/to/video.mp4" type="video/mp4" />
        <track
          src="/path/to/captions.vtt"
          kind="subtitles"
          srcLang="en"
          label="English"
        />
        Your browser does not support the video tag.
      </video>
    </div>
  );
};

export default Video;
