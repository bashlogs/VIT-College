-- MariaDB dump 10.19  Distrib 10.6.11-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: DS
-- ------------------------------------------------------
-- Server version	10.6.11-MariaDB-2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Orders`
--

DROP TABLE IF EXISTS `Orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Orders` (
  `cust_no` int(11) NOT NULL AUTO_INCREMENT,
  `firstname` varchar(255) DEFAULT NULL,
  `lastname` varchar(255) DEFAULT NULL,
  `phone_no` text DEFAULT NULL,
  `bill` int(11) DEFAULT NULL,
  `weight` int(11) DEFAULT NULL,
  `time` int(11) DEFAULT NULL,
  `status` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`cust_no`)
) ENGINE=InnoDB AUTO_INCREMENT=34 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Orders`
--

LOCK TABLES `Orders` WRITE;
/*!40000 ALTER TABLE `Orders` DISABLE KEYS */;
INSERT INTO `Orders` VALUES (1,'Mayur','Khadde','-1082195811',120,23,360,'Done'),(2,'Mayur','Khadde','-1082195811',120,23,360,'Done'),(3,'Mayur','Khadde','7507738781',120,23,360,'Done'),(4,'_','','113808',210,280,130,'Done'),(5,'Mayur','Khadde','7507738781',81920,0,24348,'Done'),(6,'mayur','Khadde','750387832',81920,0,24348,'Done'),(7,'Mayur','Khadde','382773699',210,280,130,'Done'),(8,'mayur','Khadde','3928326666',160,240,90,'Done'),(9,'Mayur','Khadde','32111111',120,160,80,'Done'),(10,'Mayur','Khadde','7507732923',210,280,130,'Done'),(11,'Mayur','Khadde','32838922341',210,280,130,'Done'),(12,'Mayur','Khadde','456789234',210,280,130,'Done'),(13,'qwert','asdf','1234',210,280,130,'Done'),(14,'wewew','uij','7507738781',210,280,130,'Pending'),(15,'poiu','yuio','123456',210,280,130,'Pending'),(16,'Mayur','Khadde','345678823',210,280,130,'Pending'),(17,'Mayur','Khads','12653784',190,240,125,'Pending'),(18,'Mayur','Khadde','234567823',210,280,130,'Pending'),(19,'qewr','wewre','234',130,160,85,'Pending'),(20,'adsf','wwer','1234',130,160,85,'Pending'),(21,'ewrtds','weresa','1234',130,160,85,'Pending'),(22,'eed','wwere','123',130,160,85,'Pending'),(23,'1234','1234','1234',130,160,85,'Done'),(24,'123','23','123',130,160,85,'Pending'),(25,'adsff','adsfd','123',130,160,85,'Pending'),(26,'Majhjh','ugesad','123',130,160,85,'Pending'),(27,'jhasdasd','asdfewq','1234',130,160,85,'Pending'),(28,'sfds','adsaS','123',130,160,85,'Pending'),(29,'Mayur','Khadde','7507738781',130,160,85,'Pending'),(30,'Mayur','Khadde','7507738781',210,280,130,'Pending'),(31,'Mayur','Khadde','23783289187',130,160,85,'Pending'),(32,'Mayur','Khadde','1234',130,160,85,'Pending'),(33,'mayur','khadde','34532',60,80,40,'Pending');
/*!40000 ALTER TABLE `Orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `cust_no` int(11) NOT NULL AUTO_INCREMENT,
  `firstname` varchar(255) DEFAULT NULL,
  `lastname` varchar(255) DEFAULT NULL,
  `phone_no` text DEFAULT NULL,
  `orders` varchar(255) DEFAULT NULL,
  `bill` decimal(9,2) DEFAULT NULL,
  `weight` int(11) DEFAULT NULL,
  `time` int(11) DEFAULT NULL,
  `status` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`cust_no`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (1,'mayur','khadde','23','1,1,0,0',196.20,653,120,'Done'),(3,'mayur','khadde','2344321','3.50,3.20,0.00,1.50',276.00,8200,220,'Pending'),(4,'mayur','khadde','2341','2.50,4.20,0.00,-0.00',201.00,6700,140,'Done'),(5,'mayur','khadde','234','2.40,3.12,0.00,0.82',165.60,5520,100,'Done'),(6,'mayur','khadde','12344321','2.40,3.12,0.00,0.00',165.60,5520,100,'Pending'),(7,'mayur','khadde','12334','2.50,4.20,0.00,0.00',201.00,6700,140,'Pending'),(8,'mayur','khadde','2341','2.34,0.00,0.00,3.21',230.70,5550,160,'Pending'),(9,'mayur','khadde','12341','2.42,4.21,0.00,0.00',198.90,6630,120,'Pending'),(10,'mayur','khadde','32432','2.32,4.21,0.00,0.00',195.90,6530,120,'Pending'),(11,'dsf','ds','123','2.32,3.21,0.00,0.00',165.90,5530,100,'Done'),(12,'masf','www','123','2.32,3.24,0.00,0.00',166.80,5560,100,'Done'),(13,'asd','qe','23','2.32,3.21,0.00,0.00',165.90,5530,100,'Done'),(14,'sertyj','lirfghjk','237654','2.32,3.00,3.21,0.00',223.80,8530,115,'Pending'),(15,'qwr','we','123','2.32,3.20,0.00,0.00',165.60,5520,100,'Pending'),(16,'mayur','khadd','12','2.32,0.00,2.21,0.00',113.80,4530,50,'Pending'),(17,'Mayur','Khadde','7507738781','2.34,3.45,0.00,0.00',173.70,5790,100,'Pending'),(18,'Mayur','KHadde','7507738781','2.34,3.21,0.00,0.00',166.50,5550,100,'Pending'),(19,'Mayur','dfgh','12','2.31,3.21,0.00,0.00',165.60,5520,100,'Pending'),(20,'qwe','qwer','134','2.32,4.32,0.00,0.00',199.20,6640,120,'Pending'),(21,'Mayur','Khadde','7507738781','2.34,3.21,2.12,0.00',208.90,7670,110,'Pending'),(22,'1234','123','1234','2.32,0.00,0.00,0.00',69.60,2320,40,'Done'),(23,'Mayur','Khadde','7507738781','2.32,3.12,4.53,1.23',315.30,11200,165,'Pending'),(24,'Mayur','Khadde','12345','2.34,3.43,2.31,3.21',379.80,11290,230,'Pending');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `data`
--

DROP TABLE IF EXISTS `data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `data` (
  `cust_id` int(11) NOT NULL,
  `order` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`cust_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `data`
--

LOCK TABLES `data` WRITE;
/*!40000 ALTER TABLE `data` DISABLE KEYS */;
INSERT INTO `data` VALUES (29,'1,1,1,1'),(30,'2,2,2,1'),(31,'1,1,1,1'),(32,'1,1,1,1'),(33,'1,0,0,0'),(38,'1,1,1,1');
/*!40000 ALTER TABLE `data` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `login`
--

DROP TABLE IF EXISTS `login`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `login` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `login`
--

LOCK TABLES `login` WRITE;
/*!40000 ALTER TABLE `login` DISABLE KEYS */;
INSERT INTO `login` VALUES (1,'mayur','khadde');
/*!40000 ALTER TABLE `login` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-02-07  1:28:44
