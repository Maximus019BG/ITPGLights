import React from "react";

const Video = () => {
  return (
    <div className="video-container relative flex h-screen">
      <video className="max-w-full" autoPlay controls>
        <source src="/forest.mp4" type="video/mp4" />
        Your browser does not support the video tag.
      </video>
    </div>
  );
};

export default Video;
