-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 15, 2023 at 10:02 AM
-- Server version: 10.4.21-MariaDB
-- PHP Version: 8.0.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `medical_store`
--

-- --------------------------------------------------------

--
-- Table structure for table `medicine`
--

CREATE TABLE `medicine` (
  `mbno` varchar(10) NOT NULL,
  `mname` varchar(50) DEFAULT NULL,
  `mcompany` varchar(50) DEFAULT NULL,
  `mqty` int(10) DEFAULT NULL,
  `mexpdate` varchar(50) DEFAULT NULL,
  `mpurdate` varchar(50) DEFAULT NULL,
  `mtype` varchar(30) DEFAULT NULL,
  `mpurprice` float DEFAULT NULL,
  `msaleprice` float DEFAULT NULL,
  `mrackno` varchar(20) DEFAULT NULL,
  `sid` int(10) DEFAULT NULL,
  `sname` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `medicine`
--

INSERT INTO `medicine` (`mbno`, `mname`, `mcompany`, `mqty`, `mexpdate`, `mpurdate`, `mtype`, `mpurprice`, `msaleprice`, `mrackno`, `sid`, `sname`) VALUES
('1', 'bhomu bam', 'acbjfav', 45, '2-2-2022', '1-2-2022', 'Balm', 78, 79, 'B', 2, 'rupesh'),
('12', 'domo', 'demo', 14, '28-12-2024', '27-12-2021', 'Insulin', 55, 65, 'a', 2, 'rupesh'),
('E20302', 'Mecobion-OD', 'Medley pharmacceuticals ltd', 100, '8-2024', '26-01-2020', 'Tablet', 50, 78, 'm', 2, 'rupesh'),
('l127', 'cystone', 'himalaya', 60, '8-2024', '26-01-2020', 'Tablet', 60, 80, 'c', 7, 'baban marne'),
('m145', 'metxl-25', 'meta parma', 10, '8-2024', '26-01-2020', 'Tablet', 80, 100, 'm', 3, 'Ganesh marne'),
('p20776', 'GlimiSave-4', 'Gilmepiride', 100, '8-2024', '15-08-2020', 'Tablet', 70, 87, 'g', 1, 'akshay chame'),
('q111', 'vix500', 'vix  pharma', 10, '8-2024', '15-08-2020', 'Tablet', 25, 50, 'v1', 2, 'rupesh'),
('r2025', 'tiger balm', 'makson pvt ltd', 50, '8-2024', '15-08-2020', 'Balm', 15, 27, 'x', 6, 'nitin pawar'),
('s1234', 'combiflan-5mg', 'combifan pharma', 10, '8-2024', '01-01-2020', 'Tablet', 50, 100, 'c1', 2, 'rupesh'),
('s167', 'supradin', 'supra phrma', 50, '8-2024', '01-01-2020', 'Tablet', 17, 30, 's', 4, 'Mayur joshi'),
('w12', 'crocine', 'crocine pharma', 10, '8-2024', '01-01-2020', 'Tablet', 50, 100, 'c`', 2, 'rupesh');

-- --------------------------------------------------------

--
-- Table structure for table `supplier`
--

CREATE TABLE `supplier` (
  `sid` int(10) NOT NULL,
  `sname` varchar(50) DEFAULT NULL,
  `saddress` varchar(100) DEFAULT NULL,
  `sphoneno` varchar(20) DEFAULT NULL,
  `semailid` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `supplier`
--

INSERT INTO `supplier` (`sid`, `sname`, `saddress`, `sphoneno`, `semailid`) VALUES
(1, 'akshay chame', 'ausa road latur-413512', '9604856881', 'akshay@gmail.com'),
(2, 'rupesh', 'ausa', '9869663450', 'rupesh@gmail.com'),
(3, 'Ganesh marne', 'ausa road latur-413512', '9922205610', 'ganesh@gmail.com'),
(4, 'Mayur joshi', 'ausa road latur-413512', '98989863620', 'mayur@gmail.com'),
(5, 'dinesh divekar', 'ausa road latur-413512', '89898565601', 'dinesh@gmail.com'),
(6, 'nitin pawar', 'ausa road latur-413512', '0202546468567', 'nitin@gmail.com'),
(7, 'baban marne', 'ausa road latur-413512', '7788556611', 'baban@gmail.com'),
(8, 'ganesh pawale', 'ausa road latur-413512', '020-25487978', 'ganesh@gmail.com'),
(9, 'akash rahane', 'MIDC', '7858963258', 'aksha@gmail.com');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `medicine`
--
ALTER TABLE `medicine`
  ADD PRIMARY KEY (`mbno`),
  ADD KEY `sid` (`sid`);

--
-- Indexes for table `supplier`
--
ALTER TABLE `supplier`
  ADD PRIMARY KEY (`sid`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `supplier`
--
ALTER TABLE `supplier`
  MODIFY `sid` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `medicine`
--
ALTER TABLE `medicine`
  ADD CONSTRAINT `medicine_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `supplier` (`sid`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
