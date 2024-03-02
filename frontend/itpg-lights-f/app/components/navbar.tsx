import React from "react";
import Image from "next/image";
import Image1 from "next/image";


const Navbar = () => {
  return (
    <div>
      <nav className="bg-white h-20">
        <div>
            <Image1 className=" relative top-5 left-4 inline-flex items-center justify-between" src="/logo.png" alt="Logo" width={50} height={50} />
        </div>
        <ul className=" relative bottom-8 left-3/4 inline-flex items-center justify-between space-x-16">
          <li className=" hover:bg-slate-300 p-3 rounded-xl cursor-pointer">
            <Image src="/home.png" alt="Home" width={30} height={30} />
          </li>
          <li className=" hover:bg-slate-300 p-3 rounded-xl cursor-pointer">
            <Image src="/account.png" alt="Account" width={25} height={25} />
          </li>
          <li className=" hover:bg-slate-300 p-2 rounded-xl cursor-pointer">
            <Image src="/settings.png" alt="Settings" width={50} height={50} />
          </li>
        </ul>
      </nav>
    </div>
  );
};

export default Navbar;