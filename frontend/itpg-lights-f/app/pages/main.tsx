import React from 'react';
import Navbar from '../components/navbar';
import Content from '../components/content';

const Main = () => {
  return (
    <div>
        <div>
            <Navbar/>
        </div>
        <div>
            <Content/>
        </div>
    </div>
  )
}

export default Main