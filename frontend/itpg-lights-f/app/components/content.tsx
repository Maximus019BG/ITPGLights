import React from "react";
import Image from "next/image";
const AnyReactComponent = () => <div>" "</div>;

const Content = () => {

  const defaultProps = {
    center: {
      lat: 10.99835602,
      lng: 77.01502627
    },
    zoom: 11
  };

  return (
    <div className=" mt-12 ">
      <div className=" absolute flex flex-col justify-center left-2/3">

        <div className=" relative flex flex-col justify-center right-1/2">
          <h2 className=" text-black text-xl dark:text-white">Здравейте,</h2>
          <h1 className=" text-black font-extrabold text-2xl">Име Фамилия</h1>
        </div>

        <div className=" relative inline-flex pt-12 right-72">
          <div className=" flex flex-col justify-center items-center p-4">
            <Image src="/lamp1.png" alt="Image" width={75} height={75} />
            <h3 className=" text-black">Основни</h3>
          </div>

          <div className=" flex flex-col justify-center items-center p-4">
            <Image src="/lamp2.png" alt="Image" width={75} height={75} />
            <h3 className=" text-black">Градина</h3>
          </div>

          <div className=" flex flex-col justify-center items-center p-4">
            <Image src="/lamp3.png" alt="Image" width={75} height={75} />
            <h3 className=" text-black">Сотира</h3>
          </div>

          <div className=" flex flex-col justify-center items-center p-4">
            <Image src="/lamp4.png" alt="Image" width={75} height={75} />
            <h3 className=" text-black">Сграда</h3>
          </div>
        </div>


      </div>
    </div>
  );
};

export default Content;
