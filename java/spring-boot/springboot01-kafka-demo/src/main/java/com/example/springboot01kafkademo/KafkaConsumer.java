package com.example.springboot01kafkademo;

import org.springframework.context.annotation.Configuration;
import org.springframework.kafka.annotation.KafkaListener;

@Configuration
public class KafkaConsumer {

    @KafkaListener(topics = "first")
    public void consumerTopic(String msg){
        System.out.println("收到消息：" + msg);
    }
}
