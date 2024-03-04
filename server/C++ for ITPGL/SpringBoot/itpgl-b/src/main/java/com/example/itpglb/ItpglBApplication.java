package com.example.itpglb;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;


@SpringBootApplication
public class ItpglBApplication {

	public static void main(String[] args) {
		SpringApplication.run(ItpglBApplication.class, args);
	}

	@RestController
	class HelloWorldController {
		@GetMapping("/")
		public String hello() {
			return "Hello World 1";
		}	
		@PostMapping("/POST")
		public String postMethodName(@RequestBody String entity) {
			//TODO: process POST request
			
			return entity;
		}
			
	}
}
