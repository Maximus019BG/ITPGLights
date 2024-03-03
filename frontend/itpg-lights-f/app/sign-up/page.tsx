import React from "react";
import Navbar from "../components/navbar";
import Form from "../components/sign-up-form";
import Video from "../components/sign-up-video";

const Sign_up = () => {
  return (
    <div>
      <div>
        <Navbar/>
      </div>
      <div>
        <Form />
      </div>
      <div>
        <Video/>
      </div>
    </div>
  );
};

export default Sign_up;
