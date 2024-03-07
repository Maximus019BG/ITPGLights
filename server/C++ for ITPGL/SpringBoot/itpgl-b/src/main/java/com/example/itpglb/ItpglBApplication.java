package com.example.itpglb;

import com.example.*;

import com.example.itpglb.Main;

// import com.mongodb.client.MongoClient;
// import com.mongodb.client.MongoClients;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.*;
@CrossOrigin(origins = "http://localhost:3000")

@SpringBootApplication
@RestController
public class ItpglBApplication {

	public static void main(String[] args) {
		SpringApplication.run(ItpglBApplication.class, args);
		Main.ConnectDevice();
		
	}

	
	// public MongoClient mongoClient() {
	
	// 	return MongoClients.create("mongodb+srv://ITPGL:L5A8l0z6SSSok6PF@itpgl-cluster.28j8bcs.mongodb.net/?retryWrites=true&w=majority&appName=ITPGL-cluster");
	// }

		
	
		@GetMapping("/")
		public String hello() {
	
			Main.ConnectDevice();
			return "<h1> END <h1>" ;
		}

	
	}
	
